//
// Created by mmsal on 4/28/2023.
//

#ifndef TPP_CPU_H
#define TPP_CPU_H
#include <map>
#include <cstddef>
#include <vector>
class CPU{

private:
//    std::map<int,int>memory;
//    std::vector<Instruction> instructions;
    double regn;
    int fregn;


public:

//    using Instruction = void (CPU::*)();//chat

    template<class T>
    T load(T address1);
    template <class T>
    void store(T reg1, size_t address1);

    template<class T>
    T add(T reg1, T reg2);


//    void storeInstruction(std::function<void()> instruction);

    void jump();
    void find(int address1);



    void loadInstruction();

//    void multiply(T val, T val2);

    static float multiply(float val, float val2);
};


//extern CPU oneCPU;

#endif //TPP_CPU_H
