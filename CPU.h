//
// Created by mmsal on 4/28/2023.
//

#ifndef TPP_CPU_H
#define TPP_CPU_H
#include <map>
#include <cstddef>

class CPU{
private:
    std::map<int,int>memory;
    double regn;
    int fregn;
public:
    template<class T>
    T load(T address1);
    template <class T>
    void store(T reg1, size_t address1);

    template<class T>
    T add(T reg1, T reg2);
    void jump();
    void find(int address1);
};

//extern CPU oneCPU;

#endif //TPP_CPU_H
