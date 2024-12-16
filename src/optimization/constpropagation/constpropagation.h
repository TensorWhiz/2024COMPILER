
#include <memory>
#include "../../ir/temp.h"
using namespace std;
using namespace LLVMIR;
enum class Status { BOT, CONST, TOP };
struct ValueStatus {
    Status status;
    AS_operand *value;
    [[nodiscard]] bool is_bot() const { return status == Status::BOT; }
    [[nodiscard]] bool is_const() const { return status == Status::CONST; }
    [[nodiscard]] bool is_top() const { return status == Status::TOP; }
    void operator^=(ValueStatus &b) {
        if (b.status < status) {
            status = b.status;
            value = b.value;
        } else if (status == b.status && status == Status::CONST) {
                if (value->u.ICONST!=b.value->u.ICONST) {
                    status = Status::BOT;
                    value = nullptr;
                }
        }
    }
    bool operator!=(ValueStatus &b) const {
        if (status != b.status)
            return true;
        if (status != Status::CONST)
            return false;
        if (value->kind==OperandKind::ICONST) {
            return value->u.ICONST!=b.value->u.ICONST;
        }
        return true;
    }
};

struct ValueMap {
    std::map<AS_operand *, ValueStatus> value_map;
    void clear() { value_map.clear(); }
    ValueStatus get(AS_operand *key) {
        if (key!=nullptr&&key->kind==OperandKind::ICONST)
            return {Status::CONST, key};
        return value_map[key];
    }
    void set(AS_operand *key, ValueStatus value) { value_map[key] = value; }
};
typedef struct ValueMap ValueMap;

struct InstructionVisitor {
    L_stm* inst;
    L_block* bb;
    ValueStatus prev_status;
    ValueStatus cur_status;
    InstructionVisitor();
    void visit( L_stm*inst);
    void visit_phi(L_stm*inst);
    void visit_br(L_stm*inst);
    void visit_foldable(L_stm*inst);
};

AS_operand *constFold(LLVMIR::L_stm *inst);
LLVMIR::L_prog *PropagateConst(LLVMIR::L_prog *prog);
void pc();
void replaceConstant();
void condBrToJmp(LLVMIR::L_stm *inst, LLVMIR::L_block *jmp_bb, LLVMIR::L_block *invalid_bb);
void rewriteBrPhi();
void rewritePhi(L_block *bb, L_block *invalid_bb);
