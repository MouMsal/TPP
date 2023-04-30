//
// Created by mmsal on 4/28/2023.
//

#include "CPU.h"
#include "memory.h"


Memory mainMem;


template <class T>
T CPU::load(T address1){
    regn = mainMem.getVal<T>(address1);
    return regn;
}


template <class T>
void CPU::store(T reg1,size_t address1){

    mainMem.getVal<T>(address1) = reg1;
}

template <class T>
T CPU::add(T reg1, T reg2){ //Return something if it's not a reference;
    regn = reg1 + reg2;
    return regn;
}

void CPU::jump(){

}
void CPU::find(int address1){

}
template int CPU::load<int>(int);
template void CPU::store<int>(int, size_t);
template int CPU::add<int>(int, int);
template double CPU::add<double>(double, double);