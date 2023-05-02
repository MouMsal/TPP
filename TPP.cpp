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
    template <class T>
    friend T operator*(T one,T two);

        public:
    int val;
    size_t address;
public:
    Integer(int i):val(i) {
        address =0;
        memBuffer.allocateMemory(val,address); //Perhaps turn it into CPU later.
        std::cout<<"hello";

//        std::cout<<"\n"<<address;
    }
    Integer(){}
    Integer& operator=(int val1){
        this->val = val1;

        oneCPU.store(val,address);

//        std::cout<<oneCPU.load<float>(address);

        return *this;}

    Integer& operator=(Integer val1){

        this->val = val1.val;
        std::cout<<"hello";

        oneCPU.store(val,address);
//        std::cout<<oneCPU.load<float>(address);

        return *this;}
};

class Decimal {
//    template <class T>
//    friend void operator<<(std::ostream& o, T i);
    template <class T>
    friend T operator+(T one, T two);
    template <class T>
    friend T operator-(T one, T two);
    template <class T>
    friend T operator*(T one,T two);

protected:
    float val;
    size_t address;

public:
    Decimal(float f) : val(f) {
//        std::cout<<val;
        memBuffer.allocateMemory(val, address);

//        std::cout<<"\n"<<address;
    }
    Decimal() {}

    Decimal& operator=(float val1){
        this->val = val1;
        oneCPU.store(val,address);
        return *this;}

    Decimal& operator=(Decimal val1){
        this->val = val1.val;
        oneCPU.store(val,address);
        return *this;}
};


int main(){

//    Integer test1 = 25;
    Integer test2 = 30;
//    Decimal test4 = 32.24;
    Integer test3 = 4;

//    test4 = 23.12;
//    test3 = 23 + 2;

    test3 =  test2 + test3;
//    std::cout<<"\n"<<test3;


//    test1 = test2 * test3;
//    std::cout<<(test2*test3);
//    std::cout<<oneCPU.multiply(30,4);
//    test2 = 5;
//    tpp::disp(tpp::newline);

//    tpp::disp(oneCPU.multiply(3.13,2.4));
//    tpp::disp(test4);
//    tpp::disp(tpp::newline);
//    tpp::disp(test2);

//    test2 = test1 - test2;
//    z = tpp::add(test1,test2);



}

void operator<<(std::ostream& o, Integer i){o<<i.val;}

template <class T>
T operator+(T one,T two){
//    T three = 0;
    std::cout<<"\n____";
    oneCPU.load<typeof(one.val)>(one.address);
    std::cout<<"\n____";
    //    std::cout<<two.address;
    typeof(one.val) three;

    three = oneCPU.add(oneCPU.load<typeof(one.val)>(one.address)
            ,(oneCPU.load<typeof(two.val)>(two.address)));

    return three;

}

template <class T>
T operator-(T one,T two){
    typeof(one.val) three;

    three = oneCPU.add(oneCPU.load<typeof(one.val)>(one.address)
            ,-(oneCPU.load<typeof(one.val)>(two.address)));
    //Looks stupid but trying pretend to use a cpu.
    return three.val;
}

template <class T>
T operator*(T one,T two){

    T three;
//    std::cout<<"\n"<<oneCPU.load<typeof(one.val)>(one.address);


    three.val = oneCPU.multiply(oneCPU.load<typeof(one.val)>(one.address)
            ,oneCPU.load<typeof(two.val)>(two.address));

//    std::cout<<three.val;
    //Looks stupid but trying pretend to use a cpu.
    return static_cast<typeof(one.val)>(three.val);
}

