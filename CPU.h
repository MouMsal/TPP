//
// Created by mmsal on 4/28/2023.
//

#ifndef TPP_CPU_H
#define TPP_CPU_H
#include <map>
#include <cstddef>
#include <vector>
#include <iostream>
class CPU{

private:
    double regn;
    //    std::vector<Instruction> instructions; Unfinished


public:
    template<class T>
    T load(size_t address1);
    template <class T>
    void store(T reg1, size_t address1);

    template<class T>
    T add(T reg1, T reg2);
    template <class T>
    T multiply(T val, T val2);

    float divide(float val, float val2);

    template<class T>
    int modulo(T val, T num);

    /* Unfinished:
    void storeInstruction(std::function<void()> instruction);
    void jump();
    void find(int address1);
    void loadInstruction();*/
};


//extern CPU oneCPU;

#endif //TPP_CPU_H
