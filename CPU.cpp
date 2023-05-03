#include "CPU.h"
#include "memory.h"


Memory mainMem;

template <class T>
T CPU::load(size_t address1){
    regn = mainMem.getVal<T>(address1);

    return regn;
}

template <class T>
void CPU::store(T reg1,size_t address1){
    mainMem.getVal<T>(address1) = reg1;
}

template <class T>
T CPU::add(T reg1, T reg2){
    regn = reg1 + reg2;
    return regn;
}

template <class T>
T CPU::multiply(T val, T val2){
    return (val*val2);
}

float CPU::divide(float val, float val2){ //Just made it convert them to floats.
    try {

        if (val2 == 0)
            throw ("Cannot divide by zero");
    }
        catch(char const *message)
        {
            std::cout << message;
            return 0;
        }
    return (val/val2);
}

template <class T>
int CPU::modulo(T val,T num){ //Integer Return
    return (val%num);
}

template int CPU::load<int>(size_t);
template float  CPU::load<float>(size_t);
template double CPU::load<double>(size_t);
template void CPU::store<int>(int, size_t);
template void CPU::store<float>(float, size_t);
template void CPU::store<double>(double, size_t);
template int CPU::add<int>(int, int);
template double CPU::add<double>(double, double);
template int CPU::multiply(int val, int val2);
template float CPU::multiply(float val, float val2);
template double CPU::multiply(double val, double val2);
template int CPU::modulo<int>(int val,int num);



/* Unfinished
//void CPU::storeInstruction( instruction){
//    instructions.push_back(instruction);
//}


void CPU::jump(){

}
void CPU::find(int address1){

}

enum OPcode {
    ADD = 1,
    SUB = 2,
    MUL = 3,
    DIV = 4,
    JMP = 5,
    JZ = 6,
    JNZ = 7,
    LOAD = 8,
    STORE = 9,
    HLT = 10
};

struct Intructions{

    OPcode opcode;
    size_t address1;
    size_t address2;
    std::string label;

};*/