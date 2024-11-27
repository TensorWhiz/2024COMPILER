#include "bg_llvm.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <iostream>
#include "graph.hpp"
#include "printLLVM.h"
#include "temp.h"
/* graph on AS_ basic blocks. This is useful to find dominance
   relations, etc. */

using namespace std;
using namespace LLVMIR;
using namespace GRAPH;

static Graph<L_block*> RA_bg;
static unordered_map<Temp_label*, L_block*> block_env;

Graph<L_block*>& Bg_graph() {
    return RA_bg;
}
unordered_map<Temp_label*, L_block*>& Bg_block_env() {
    return block_env;
}

Node<L_block*>* Look_bg(L_block* b) {
    Node<L_block*>* n1 = nullptr;
    for (auto n : *RA_bg.nodes()) {
        if (n.second->nodeInfo() == b) {
            n1 = n.second;
            break;
        }
    }
    if (n1 == nullptr)
        return RA_bg.addNode(b);
    else
        return n1;
}

static void Enter_bg(L_block* b1, L_block* b2) {
    Node<L_block*>* n1 = Look_bg(b1);
    Node<L_block*>* n2 = Look_bg(b2);
    RA_bg.addEdge(n1, n2);
    return;
}

/* input LLVMIR::L_block* *List after instruction selection for each block,
    generate a graph on the basic blocks */

Graph<L_block*>& Create_bg(list<L_block*>& bl) {
    RA_bg = Graph<L_block*>();
    block_env = unordered_map<Temp_label*, L_block*>();

    for (auto block : bl) {
        block_env.insert({block->label, block});
        RA_bg.addNode(block);
    }

    for (auto block : bl) {
        unordered_set<Temp_label*> succs = block->succs;
        for (auto label : succs) {
            Enter_bg(block, block_env[label]);
        }
    }
    return RA_bg;
}

// maybe useful
static void DFS(Node<L_block *> *r, Graph<L_block *> &bg, int color)
{
     if(r->color == color)
        return;

    r->color = color;
    for(auto &succ_id: *r->succ()){
        DFS(bg.mynodes[succ_id], bg, color);
    }
}

/**
 * @note 删除不可达节点
 * @note SSA的要求是起始节点必须唯一，这里直接从src节点遍历图，然后删除未着色的节点即可。
 */

void SingleSourceGraph(Node<L_block *> *r, Graph<L_block *> &bg, L_func *fun)
{
       // 0
       //保存初始颜色 default_color，用于区分未被访问的节点。
        int default_color = r->color;
        //设置新的颜色值 new_color，用于标记从源节点 r 出发时访问到的节点。
        int new_color = 1;
        //使用深度优先搜索 DFS 遍历图 bg，从源节点 r 开始，将所有可达节点标记为 new_color
        DFS(r, bg, new_color);

        for(auto &pair : bg.mynodes){
            Node<L_block*>* node = pair.second;
            if(node->color == default_color){
                // 删除入边
                while(true){
                    if(node->pred()->empty())
                        break;
                    auto it = node->pred()->begin();
                    if(it==node->pred()->end())
                        break;
                    bg.rmEdge(node, bg.mynodes[*it]);
                }

                // 删除出边
                while(true){
                    if(node->succ()->empty())
                        break;
                    auto it = node->succ()->begin();
                    if(it==node->succ()->end())
                        break;
                    bg.rmEdge(node, bg.mynodes[*it]);
                }

                // 删除节点
                node->nodeInfo()->instrs.clear();
                node->nodeInfo()->succs.clear();
                bg.rmNode(node);
            }
        }
        //恢复颜色
        DFS(r, bg, default_color);
        // FILE* f=fopen("./tests/singleSource.txt", "a");
        // Show_graph(f, bg);
        // fprintf(f, "\n");
        // fclose(f);
}
void Show_graph(FILE* out,GRAPH::Graph<LLVMIR::L_block*>&bg){
    
    for(auto block_node:bg.mynodes){
        auto block=block_node.second->info;
        fprintf(out,"%s \n",block->label->name.c_str());
        fprintf(out,"pred  %zu  ",block_node.second->preds.size());
        for(auto pred:block_node.second->preds){
            fprintf(out,"%s  ",bg.mynodes[pred]->info->label->name.c_str());
            fprintf(out,"%d  ",bg.mynodes[pred]->color);
        }
        fprintf(out,"\n");
        fprintf(out,"succ  %zu  ",block_node.second->succs.size());
        for(auto succ:block_node.second->succs){
            fprintf(out,"%s  ",bg.mynodes[succ]->info->label->name.c_str());
            fprintf(out,"%d  ",bg.mynodes[succ]->color);
        }
        fprintf(out,"\n");
    }
}