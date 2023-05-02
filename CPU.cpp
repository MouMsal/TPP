//
// Created by mmsal on 4/28/2023.
//

#include <functional>
#include "CPU.h"
#include "memory.h"


Memory mainMem;



template <class T>
T CPU::load(size_t address1){
    regn = mainMem.getVal<T>(address1);
    std::cout<<"\n"<<address1;
    return regn;
}


template <class T>
void CPU::store(T reg1,size_t address1){
    mainMem.getVal<T>(address1) = reg1;
    std::cout<<"\n"<<address1;
//    std::cout<<"\n"<<regn;
}

template <class T>
T CPU::add(T reg1, T reg2){ //Return something if it's not a reference;
    regn = reg1 + reg2;


    return regn;
}

//void CPU::storeInstruction( instruction){
//    instructions.push_back(instruction);
//}


void CPU::loadInstruction(){

}

template <class T>
T CPU::multiply(T val, T val2){
    //No need to work on this, fortunately.
//    float val3 = 0;
//float add = static_cast<float>(val)/100;
//    for (int i = 0; i < static_cast<int>(val2*100); i++) {
//        val3 += add;
//    }
    return (val*val2);
}
float CPU::divide(float val, float val2){


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

void CPU::jump(){

}
void CPU::find(int address1){

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

struct Intructions{

    //opcode;
    //label

};