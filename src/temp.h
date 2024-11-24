#ifndef __TEMP
#define __TEMP

#include <string>
#include <unordered_set>
enum class TempType
{
    INT_TEMP,
    INT_PTR,
    STRUCT_TEMP,//只存在于全局变量
    STRUCT_PTR
};
//IR中寄存器的抽象
struct Temp_temp
{
    int num;
    //寄存器编号
    TempType type;
    //寄存器中元素的类型
    std::string structname;
    //如果该寄存器和结构体有关则structname是其结构体的名字
    std::string varname;
    //用于debug
    int len;
    //用于区分指针和数组，当len为0时代表单个元素的指针，当len为-1时代表数组头指针，这种情况只在数组作为函数参数时存在，当len大于0时代表数组的长度
    Temp_temp(int _num,TempType _type = TempType::INT_TEMP,int _len = 0,const std::string& _sname = std::string());
};

Temp_temp* Temp_newtemp_int();
Temp_temp* Temp_newtemp_int_ptr(int len);
Temp_temp* Temp_newtemp_struct(const std::string& name);
Temp_temp* Temp_newtemp_struct_ptr(int len, const std::string& name);

typedef std::unordered_set<Temp_temp*> TempSet_;
typedef TempSet_* TempSet;

void TempSet_add(TempSet tl, Temp_temp* t);
bool TempSet_contains(TempSet tl, Temp_temp* t);
TempSet TempSet_union(TempSet tl1, TempSet tl2);
TempSet TempSet_diff(TempSet tl1, TempSet tl2);
bool TempSet_eq(TempSet tl1, TempSet tl2);
void TempSet_remove(TempSet tl, Temp_temp* t);


struct TempDef
{
    TempType kind;
    int len;
    std::string structname;
    TempDef(TempType _kind = TempType::INT_TEMP,int _len = 0,const std::string &_structname = std::string());
};

//标签的抽象
struct Temp_label
{
    std::string name;
    Temp_label(std::string _name);
};

Temp_label* Temp_newlabel();
Temp_label* Temp_newlabel_named(const std::string &name);

//全局变量的抽象
struct Name_name
{
    Temp_label *name;//全局变量的name
    TempType type;//元素的类型
    std::string structname;//如果该全局变量和结构体有关则structname是其结构体的名字
    int len;
    Name_name(Temp_label *_name,TempType _type,int _len = 0,const std::string &_structname = std::string());
};

Name_name *Name_newname_int(Temp_label *name);
Name_name *Name_newname_int_ptr(Temp_label *name,int len);
Name_name *Name_newname_struct(Temp_label *name,const std::string &structname);
Name_name *Name_newname_struct_ptr(Temp_label *name,int len,const std::string &structname);

enum class OperandKind
{
    TEMP, NAME, ICONST
};
//指令中的运算对象
struct AS_operand 
{
    OperandKind kind;
    union {
        Temp_temp *TEMP;
        Name_name *NAME;
        int ICONST;
    } u;

    bool operator == (const AS_operand &a) const{
        return kind==a.kind && u.TEMP==a.u.TEMP;
    }
};

AS_operand* AS_Operand_Temp(Temp_temp *temp);
AS_operand* AS_Operand_Name(Name_name *name);
AS_operand* AS_Operand_Const(int iconst);

#endif
