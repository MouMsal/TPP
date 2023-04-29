#include <map>
#include <vector>
#include <iostream>

#include "Memory.h"
#include "CPU.h"

extern CPU oneCPU;

//class DataTypes;

class Integer;


//Memory oneMemory;
namespace tpp {
    template<class T>
    T add(T val1, T val2) {

        return 1;
    }

    template<class T>
    void disp(T val) {
        std::cout << val;
    }
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
        Memory mainMem(val,address);
    }
    Integer(){}

    //Memory mainMem(val); Put this in the overloaded = op later;
};

int main(){
    Integer test1 = 25;
    Integer test2 = 30;
    Integer test3 = 4;
    test3 = (test1 + test2);
    tpp::disp(test1);

    //    tpp::disp(test2);

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