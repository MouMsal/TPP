#include <map>
#include <vector>
#include <iostream>

#include "Memory.h"
#include "CPU.h"

extern CPU oneCPU;

//class DataTypes;


Memory memBuffer;

class Integer;

namespace tpp {
    template<class T>
    T add(T val1, T val2) {

        return 1;
    }

    template<class T>
    void disp(T val) {
        std::cout << val;
    }
    std::string newline = "\n";
}
class Integer{
    friend void operator<<(std::ostream& o, Integer i);
//    friend Integer operator+(Integer one,Integer two);
    template <class T>
    friend T operator+(T one,T two);
    template <class T>
    friend T operator-(T one,T two);
protected:
    int val;
    size_t address;
public:
    Integer(int i):val(i) {
        memBuffer.allocateMemory(val,address);
        std::cout<<"\n"<<address;
    }
    Integer(){}
    Integer& operator=(int val1){
        this->val = val1;
        return *this;}
};

class Decimal {
//    template <class T>
//    friend void operator<<(std::ostream& o, T i);
    template <class T>
    friend T operator+(T one, T two);
    template <class T>
    friend T operator-(T one, T two);

protected:
    float val;
    size_t address;

public:
    Decimal(float f) : val(f) {
        memBuffer.allocateMemory(val, address);}
    Decimal() {}

    Decimal& operator=(float val1){
        this->val = val1;
        return *this;}
};


int main(){

    Integer test1 = 25;
    Integer test2 = 30;
    Integer test3 = 4;

    Decimal test4 = 32.24;
    test4 = 23.12;
    test2 = 5;
    test3 = (test1 + test2);

//    tpp::disp(test4);
//    tpp::disp(tpp::newline);
    tpp::disp(test2);

//    test2 = test1 - test2;
//    z = tpp::add(test1,test2);

    std::cout<<"\n";

}

void operator<<(std::ostream& o, Integer i){o<<i.val;}

template <class T>
T operator+(T one,T two){
    //I will need to replace with CPU add soon.

    T three;
    three.val = oneCPU.add(one.val,two.val);
    return three.val;

}


template <class T>
T operator-(T one,T two){
    //I will need to replace with CPU add soon.
    T three;

    three.val = oneCPU.add(oneCPU.load(one.address),-(oneCPU.load(two.address)));
    //Looks stupid but trying pretend to use a cpu.
    return three.val;
}