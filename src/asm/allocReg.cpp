#include "allocReg.h"
using namespace std;
using namespace ASM;
#include <cassert>
#include <stack>
using namespace GRAPH;
#include "printASM.h"
#include "register_rules.h"
#define MYDEBUG() printf("%s:%d\n", __FILE__, __LINE__)
#include <sstream>
#include <iostream>
stack<Node<RegInfo> *> reg_stack;
void getAllRegs(AS_stm *stm, vector<AS_reg *> &defs, vector<AS_reg *> &uses)
{
    switch (stm->type)
    {
    case AS_stmkind::BINOP:
        getDefReg(stm->u.BINOP->dst, defs);
        getUseReg(stm->u.BINOP->left, uses);
        getUseReg(stm->u.BINOP->right, uses);
        break;
    case AS_stmkind::MOV:
        getDefReg(stm->u.MOV->dst, defs);
        getUseReg(stm->u.MOV->src, uses);
        break;
    case AS_stmkind::MOVZ:
        getDefReg(stm->u.MOVZ->dst, defs);
        getUseReg(stm->u.MOVZ->src, uses);
        break;
    case AS_stmkind::MOVK:
        getDefReg(stm->u.MOVK->dst, defs);
        getUseReg(stm->u.MOVK->src, uses);
        break;
    case AS_stmkind::LDR:
        getDefReg(stm->u.LDR->dst, defs);
        getUseReg(stm->u.LDR->ptr, uses);
        break;
    case AS_stmkind::STR:
        getUseReg(stm->u.STR->src, uses);
        getUseReg(stm->u.STR->ptr, uses);
        break;
    case AS_stmkind::CMP:
        getUseReg(stm->u.CMP->left, uses);
        getUseReg(stm->u.CMP->right, uses);
        break;
    case AS_stmkind::ADR:
        getDefReg(stm->u.ADR->reg, defs);
        break;
    default:
        break;
    }
}

void getDefReg(AS_reg *reg, vector<AS_reg *> &defs)
{
    if (!reg)
    {
        return;
    }
    switch (reg->type)
    {
    case AS_type::Xn:
    case AS_type::Wn:
    {
        defs.push_back(reg);
        break;
    }
    case AS_type::ADR:
    {
        assert(0);
    }

    default:
        break;
    }
}
void getUseReg(AS_reg *reg, vector<AS_reg *> &uses)
{
    if (!reg)
    {
        return;
    }
    switch (reg->type)
    {
    case AS_type::Xn:
    case AS_type::Wn:
    {
        uses.push_back(reg);
        break;
    }
    case AS_type::ADR:
    {
        if (reg->u.add->base->type == AS_type::Xn)
        {
            uses.push_back(reg->u.add->base);
        }
        if (reg->u.add->reg)
        {
            uses.push_back(reg->u.add->reg);
        }
        break;
    }

    default:
        break;
    }
}
void vreg_map(AS_reg *reg, unordered_map<int, Node<RegInfo> *> &regNodes)
{
    switch (reg->type)
    {
    case AS_type::Xn:
    case AS_type::Wn:
    {
        int regNo = reg->u.offset;
        if (regNo < 100)
            return;
        reg->u.offset = regNodes[regNo]->info.color;
        break;
    }
    case AS_type::ADR:
    {
        assert(0);
    }
    default:
        break;
    }
};
void forwardLivenessAnalysis(std::list<InstructionNode *> &liveness, std::list<AS_stm *> &as_list)
{
    unordered_map<string, InstructionNode *> blocks;
    for (const auto &stm : as_list)
    {
        InstructionNode *node = new InstructionNode(stm, {}, {}, {}, {});
        liveness.push_back(node);
        vector<AS_reg *> defs;
        vector<AS_reg *> uses;

        switch (stm->type)
        {
        case AS_stmkind::LABEL:
            blocks.emplace(stm->u.LABEL->name, node);
        default:
            getAllRegs(stm, defs, uses);
            break;
        }

        for (auto &x : defs)
        {
            if (x->u.offset >= 100)
            {
                node->def.emplace(x->u.offset);
            }
            assert(x->type != AS_type::ADR);
        }

        for (auto &x : uses)
        {
            if (x->u.offset >= 100)
            {
                node->use.emplace(x->u.offset);
            }
            assert(x->type != AS_type::ADR);
        }
    }

    setControlFlowDiagram(liveness, blocks);
}
void setControlFlowDiagram(std::list<InstructionNode *> &nodes, unordered_map<string, InstructionNode *> &blocks)
{
    for (auto it = nodes.begin(); it != nodes.end(); ++it)
    {
        InstructionNode *currentNode = *it; // 当前节点
        InstructionNode *nextNode = nullptr;
        auto nextIt = std::next(it); // 获取下一个元素的迭代器
        if (nextIt != nodes.end())
        {
            nextNode = *nextIt; // 如果存在下一个节点，则获取它
        }
        switch (currentNode->raw->type)
        {
        case AS_stmkind::RET:

            break;
        case AS_stmkind::B:
            currentNode->sucessor.emplace(blocks[currentNode->raw->u.B->jump->name]);
            break;
        case AS_stmkind::BCOND:
            currentNode->sucessor.emplace(blocks[currentNode->raw->u.BCOND->jump->name]);
            if (nextNode)
            {
                currentNode->sucessor.emplace(nextNode);
            }
            break;
        default:
            if (nextNode)
            {
                currentNode->sucessor.emplace(nextNode);
            }
            break;
        }
    }
}
void init(std::list<InstructionNode *> &nodes, unordered_map<int, Node<RegInfo> *> &regNodes, Graph<RegInfo> &interferenceGraph, std::list<ASM::AS_stm *> &as_list)
{
    assert(reg_stack.empty());
    bool changed;

    int set_size = 0;
    do
    {
        changed = false;
        for (auto it = nodes.rbegin(); it != nodes.rend(); ++it)
        {
            InstructionNode *n = *it;
            n->previous_in = n->in;
            n->previous_out = n->out;

            if (n->sucessor.size())
                for (InstructionNode *s : n->sucessor)
                {
                    n->out.insert(s->in.begin(), s->in.end());
                }
            // std::set<int> diff;
            // std::set_difference(n->out.begin(), n->out.end(), n->def.begin(), n->def.end(), std::inserter(diff, diff.end()));
            // diff.insert(n->use.begin(), n->use.end());

            // n->in = diff;
            n->in.clear();
            std::set_difference(n->out.begin(), n->out.end(), n->def.begin(), n->def.end(), std::inserter(n->in, n->in.end()));
            n->in.insert(n->use.begin(), n->use.end());
            set_size += n->in.size();
            // printf("%d += %d ,%d ",n->in.size(), set_size,nodes.size());
            if (n->in != n->previous_in || n->out != n->previous_out)
            {
                changed = true;
            }
        }

    } while (changed);
    set<int> regs;
    set<int> defs;
    set<int> uses;

    for (auto &x : nodes)
    {
        defs.insert(x->def.begin(), x->def.end());
        uses.insert(x->use.begin(), x->use.end());
    }

    regs.insert(defs.begin(), defs.end());
    regs.insert(uses.begin(), uses.end());
    int ijj = 0;
    for (auto x : regs)
    {
        regNodes.insert({x, interferenceGraph.addNode({x, x, 0, 0, 0})});
        // printf("%d:%lu ", ++ijj, regs.size());
    }

    for (auto x : nodes)
    {
        std::vector<int> vec(x->in.begin(), x->in.end());
        for (int i = 0; i < vec.size(); i++)
        {
            for (int j = i + 1; j < vec.size(); j++)
            {
                interferenceGraph.addEdge(regNodes[vec[i]], regNodes[vec[j]]);
                interferenceGraph.addEdge(regNodes[vec[j]], regNodes[vec[i]]);
            }
        }
    }

    // 打印干扰图的边,并设置节点度数
    // std::cerr << "Interference Graph Edges:" << std::endl;
    auto nodes_ = interferenceGraph.nodes();
    for (auto &nodePair : *nodes_)
    {
        Node<RegInfo> *node = nodePair.second;
        NodeSet *successors = node->succ();
        node->info.degree = successors->size();

        // std::cerr << "Reg " << node->nodeInfo().regNum << " interferes with " << successors->size() << " Regs: ";
        // if (successors->size())
        // {
        //     for (int succKey : *successors)
        //     {
        //         std::cerr << interferenceGraph.mynodes[succKey]->info.regNum << " ";
        //     }
        // }

        // std::cerr << std::endl;
    }
    // 删除不使用的指令
    std::set<int> to_delete;
    std::set_difference(defs.begin(), defs.end(), uses.begin(), uses.end(), std::inserter(to_delete, to_delete.end()));

    for (auto &x : nodes)
        delete x;

    for (auto it = as_list.begin(); it != as_list.end();)
    {
        vector<AS_reg *> defs;
        vector<AS_reg *> uses;
        getAllRegs(*it, defs, uses);
        int n = 0;
        if (defs.size() > 0)
        {
            int regNo = defs.front()->u.offset;
            if (to_delete.find(regNo) != to_delete.end())
            {
                it = as_list.erase(it);
                continue;
            }
        }
        it++;
    }
}

//void livenessAnalysis(std::list<InstructionNode *> &nodes, std::list<ASM::AS_stm *> &as_list)
//{
    // Graph<RegInfo> interferenceGraph;
    // unordered_map<int, Node<RegInfo> *> regNodes; // 虚拟寄存器根据编号到干扰图上的映射
    // init(nodes, regNodes, interferenceGraph, as_list);

    // const int NUM_COLORS = allocateRegs.size();
    // std::vector<int> availableColors(allocateRegs.begin(), allocateRegs.end());
    // std::stack<Node<RegInfo> *> reg_stack;

    // // Simplify phase
    // for (auto &nodePair : *interferenceGraph.nodes())
    // {
    //     Node<RegInfo> *node = nodePair.second;
    //     if (node->info.degree < NUM_COLORS)
    //     {
    //         reg_stack.push(node);
    //     }
    //     else
    //     {
    //         node->info.is_spill = true;
    //     }
    // }

    // // Coloring phase
    // while (!reg_stack.empty())
    // {
    //     Node<RegInfo> *node = reg_stack.top();
    //     reg_stack.pop();

    //     std::vector<bool> colorUsed(NUM_COLORS, false);
    //     for (int neighborKey : *node->succ())
    //     {
    //         Node<RegInfo> *neighbor = interferenceGraph.mynodes[neighborKey];
    //         if (neighbor->info.color != -1)
    //         {
    //             int usedColorIndex = std::distance(availableColors.begin(), std::find(availableColors.begin(), availableColors.end(), neighbor->info.color));
    //             if (usedColorIndex < NUM_COLORS)
    //             {
    //                 colorUsed[usedColorIndex] = true;
    //             }
    //         }
    //     }

    //     int color = -1;
    //     for (int i = 0; i < NUM_COLORS; ++i)
    //     {
    //         if (!colorUsed[i])
    //         {
    //             color = availableColors[i];
    //             break;
    //         }
    //     }

    //     if (color != -1)
    //     {
    //         node->info.color = color;
    //         node->info.is_spill = false;
    //     }
    //     else
    //     {
    //         node->info.is_spill = true;
    //     }
    // }

    // // Calculate spill offsets and adjust stack pointer
    // int spillOffset = 0;
    // std::unordered_map<int, int> spillOffsets; // Store the offset for each spilled register

    // for (auto &nodePair : *interferenceGraph.nodes())
    // {
    //     Node<RegInfo> *node = nodePair.second;
    //     if (node->info.is_spill)
    //     {
    //         spillOffsets[node->info.regNum] = spillOffset;
    //         spillOffset += 8; // Assuming each register occupies 4 bytes
    //     }
    // }

    // ASM::AS_reg *sp = new ASM::AS_reg(ASM::SP,-1);

    // ASM::AS_stm *subSpStm = ASM::AS_Binop(ASM::AS_binopkind::SUB_, sp, new ASM::AS_reg(ASM::IMM, spillOffset), sp);
    // auto it = as_list.begin();
    // while (!((*it)->type == AS_stmkind::BINOP && (*it)->u.BINOP->op == AS_binopkind::SUB_))
    // {
    //     ++it;
    // }
    // it++;

    // as_list.insert(it, subSpStm);

    // // record spill registers
    // std::map<int, bool> spillRegs;
    // spillRegs.insert({XXn1, false});
    // spillRegs.insert({XXn2, false});
    // spillRegs.insert({XXn3, false});
    // spillRegs.insert({XXn4, false});

    // // Insert ldr and str instructions for spilled registers
    // for (auto it = as_list.begin(); it != as_list.end(); ++it)
    // {
    //     ASM::AS_stm *stm = *it;
    //     std::vector<ASM::AS_reg *> defs;
    //     std::vector<ASM::AS_reg *> uses;
    //     getAllRegs(stm, defs, uses);

    //     // Insert ldr for uses
    //     for (auto &reg : uses)
    //     {
    //         if (spillOffsets.find(reg->u.offset) != spillOffsets.end())
    //         {
    //             int offset = spillOffsets[reg->u.offset];

    //             // Select spill register
    //             for(auto spillReg : spillRegs)
    //             {
    //                 if (!spillReg.second)
    //                 {
    //                     spillRegs[spillReg.first] = true;
    //                     //cout << "Select spill register: " << spillReg.first << endl;
    //                     reg->u.offset = spillReg.first;
    //                     break;
    //                 }
    //             }

    //             if(reg->u.offset != XXn1 && reg->u.offset != XXn2 && reg->u.offset != XXn3 && reg->u.offset != XXn4)
    //             {
    //                 cout << "Error: spill register not found" << endl;
    //                 exit(1);
    //             }

    //             ASM::AS_reg *sp = new ASM::AS_reg(ASM::SP, -1);
    //             ASM::AS_address *address = new ASM::AS_address(sp, offset);
    //             ASM::AS_stm *ldrStm = ASM::AS_Ldr(new ASM::AS_reg(ASM::Xn, reg->u.offset), new ASM::AS_reg(ASM::ADR, address));
    //             it = as_list.insert(it, ldrStm);
    //             ++it;
    //         }
    //     }

    //     // Insert str for defs
    //     for (auto &reg : defs)
    //     {
    //         if (spillOffsets.find(reg->u.offset) != spillOffsets.end())
    //         {
    //             int offset = spillOffsets[reg->u.offset];

    //             // Select spill register
    //             for(auto spillReg : spillRegs)
    //             {
    //                 if (!spillReg.second)
    //                 {
    //                     spillRegs[spillReg.first] = true;
    //                     reg->u.offset = spillReg.first;
    //                     break;
    //                 }
    //             }
            
    //             // Adjust stack pointer at function exit
    //             it++;
    //             ASM::AS_address *address = new ASM::AS_address(sp, offset);
    //             ASM::AS_stm *strStm = ASM::AS_Str(new ASM::AS_reg(ASM::Xn, reg->u.offset), new ASM::AS_reg(ASM::ADR, address));
    //             it = as_list.insert(it, strStm);
    //         }
    //     }

    //     spillRegs[XXn1] = false;
    //     spillRegs[XXn2] = false;
    //     spillRegs[XXn3] = false;
    //     spillRegs[XXn4] = false;
    // }

    // // Update register mapping in the assembly code
    // for (auto &stm : as_list)
    // {
    //     std::vector<ASM::AS_reg *> defs;
    //     std::vector<ASM::AS_reg *> uses;
    //     getAllRegs(stm, defs, uses);

    //     for (auto &reg : defs)
    //     {
    //         vreg_map(reg, regNodes);
    //     }

    //     for (auto &reg : uses)
    //     {
    //         vreg_map(reg, regNodes);
    //     }
    // }

    // // Clean up
    // for (auto &nodePair : *interferenceGraph.nodes())
    // {
    //     delete nodePair.second;
    // }
//}
void livenessAnalysis(std::list<InstructionNode *> &nodes, std::list<ASM::AS_stm *> &as_list)
{
    Graph<RegInfo> interferenceGraph;
    unordered_map<int, Node<RegInfo> *> regNodes;
    init(nodes, regNodes, interferenceGraph, as_list);
    // TODO:获得干扰图后，进行寄存器分配

    // 图染色实现
    int k = allocateRegs.size();

    int processed_number = 0;    
    while(processed_number<interferenceGraph.nodes()->size()){
        // simplify
        bool changed = true;
        while(changed){
            changed = false;
            auto nodes_ = interferenceGraph.nodes();
            for (auto &nodePair : *nodes_){
                Node<RegInfo> *node = nodePair.second;
                
                if (node->info.degree < k && !node->info.bit_map){
                    reg_stack.push(node);
                    node->info.bit_map = true;
                    node->info.is_spill = false;
                    processed_number++;
                    for (int succKey : *node->succ()){
                        Node<RegInfo> *succ = interferenceGraph.mynodes[succKey];
                        succ->info.degree--;
                    }
                    changed = true;
                }
            }
        }

        // potential spill
        for(auto pair:*interferenceGraph.nodes()){
            Node<RegInfo> *node = pair.second;
            if(node->info.degree >= k && !node->info.bit_map){
                node->info.is_spill = true;
                node->info.bit_map = true;
                processed_number++;
                reg_stack.push(node);
                for(auto succKey:*node->succ()){
                    Node<RegInfo> *succ = interferenceGraph.mynodes[succKey];
                    succ->info.degree--;
                }
            }
        }
    }

    // select
    vector<Node<RegInfo>*> spill_reg;
    while(!reg_stack.empty()){
        Node<RegInfo>* node = reg_stack.top();
        reg_stack.pop();
        
        set<int> colors;
        for(auto x : allocateRegs){
            colors.insert(x);
        }

        for(auto succKey:*node->succ()){
            Node<RegInfo>* succ = interferenceGraph.mynodes[succKey];
            if(colors.find(succ->info.color) != colors.end()){
                colors.erase(succ->info.color);
            }
        }
        
        if(colors.size() == 0){
            node->info.is_spill = true;
            spill_reg.push_back(node);
        }
        else{
            node->info.is_spill = false;
            node->info.bit_map = true;
            node->info.color = *colors.begin();
        }
    }

    // color
    for(AS_stm *stmt:as_list){
        vector<AS_reg*> defs, uses;
        getAllRegs(stmt, defs, uses);

        for(AS_reg* def:defs){
            if(def->u.offset<100)
                continue;
            
            if(!regNodes.at(def->u.offset)->info.is_spill)
                vreg_map(def, regNodes);
        }

        for(AS_reg* use:uses){
            if(use->u.offset<100)
                continue;
            
            if(!regNodes.at(use->u.offset)->info.is_spill)
                vreg_map(use, regNodes);
        }
    }
    if(spill_reg.size()==0)
        return;
    AS_reg *sp = new AS_reg(AS_type::SP, -1);
    int offset = spill_reg.size() * 8;
    list<AS_stm*>::iterator it = as_list.begin();
    advance(it,6);
    int num1=offset/4095;
    int num2=offset%4095;
    for(int i=0;i<num1;i++){
        as_list.insert(it, AS_Binop(AS_binopkind::SUB_, sp, new AS_reg(AS_type::IMM, 4095), sp));
    }
    as_list.insert(it, AS_Binop(AS_binopkind::SUB_, sp, new AS_reg(AS_type::IMM, num2), sp));
    // 保存偏移量
    unordered_map<int, int> offset_map;
    for(int i = 0;i<spill_reg.size();i++){
        offset_map[spill_reg[i]->info.regNum] = i*8;
    }

    for(auto iter=as_list.begin(); iter!=as_list.end(); iter++){
        AS_stm* stm = *iter;

        vector<AS_reg*> defs, uses;
        getAllRegs(stm, defs, uses);

        set<int> spill_regs = {16, 17, 18, 19};

        for(AS_reg* use:uses){
            if(use->u.offset<100)
                continue;
            if(regNodes[use->u.offset]->info.is_spill == true){
                int offset = offset_map[use->u.offset];
                AS_address* address = new AS_address(sp, offset);
                AS_reg* ptr = new AS_reg(AS_type::ADR, address);

                int regNo = *spill_regs.begin();
                spill_regs.erase(regNo);
                use->u.offset = regNo;

                as_list.insert(iter, AS_Ldr(use, ptr));
            }
        }

        for(AS_reg* def:defs){
            if(def->u.offset<100)
                continue;
            if(regNodes[def->u.offset]->info.is_spill == true){
                int offset = offset_map[def->u.offset];
                AS_address* address = new AS_address(sp, offset);
                AS_reg* ptr = new AS_reg(AS_type::ADR, address);

                int regNo = *spill_regs.begin();
                spill_regs.erase(regNo);
                def->u.offset = regNo;

                as_list.insert(std::next(iter), AS_Str(def, ptr));
            }
        }
    }

}