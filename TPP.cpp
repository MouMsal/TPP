#include <map>
#include <vector>
#include <iostream>

//class DataTypes;

class Integer;

class Memory{

private:
    static int address1;
    int value;
public:
    Memory(int val,int& address);
    void allocateMemory(int val,int &address);
    int getNum();
};
int Memory::address1 = 0;


class CPU{
private:
    std::map<int,int>memory; //Make it so it works for all eventually. Store a bunch of "memory" objects
    int regn; //int registry n
    int fregn; //float registry n
public:
    int load(int address1){
        regn = memory[address1]; //need to fix these so that it allocates   memory and creates an address.
        return regn;
    }
    void store(int reg1,int address1){
        memory[address1] = reg1;
    }

    double add(int address1, int address2){ //Return something if it's not a reference;
        //Find the values first and load them.
        int reg1 = load(address1); //I guess Im pretending? I don't really need this tbh.
        int reg2 = load(address2);
        regn = reg1 + reg2;
        std::cout<<regn;

        return regn;
    }

    void jump(){
    }
    void find(int address1){
    }
};
CPU oneCPU;

Memory::Memory(int value,int& address)
{
    address1++;
    address = address1;
    oneCPU.store(value,address1);
}

void Memory::allocateMemory(int value,int& address){
    address1++;
    address = address1;
    oneCPU.store(value,address1);
}
int Memory::getNum(){return value;}


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
    friend void operator<<(std::ostream& o, Integer one);
//    friend Integer operator+(Integer one,Integer two);
    template <class T>
    friend T operator+(T one,T two);
    template <class T>
    friend T operator-(T one,T two);
protected:
    int val;
    int address;
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
    test1 = test1 + test2;
//    z = tpp::add(test1,test2);
    tpp::disp(test1);
}

void operator<<(std::ostream& o, Integer i){o<<i.val;}

template <class T>
T operator+(T one,T two){
    //I will need to replace with CPU add soon.

    T three;

    three.val = oneCPU.add(one.address,two.address);

    return three.val;
}

template <class T>
T operator-(T one,T two){
    //I will need to replace with CPU add soon.
    T three;
    //Function that changes the value.
    three.val = oneCPU.add(one.address,two.address);
    return three.val;
}