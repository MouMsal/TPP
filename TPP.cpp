#include <map>
#include <vector>
#include <iostream>

//class DataTypes;
class Memory;
class Integer;

class CPU{
private:
    std::map<int,int>memory;

    int regn; //int registry n
    int fregn; //float registry n
public:
    void load(int address1){
        regn = memory[address1]; //need to fix these so that it allocates   memory and creates an address.
    }
    void store(int reg1,int address1){
        //Locate
        memory[address1] = reg1;
//       memory.push_back(reg1);
    }

    double add(int address1, int address2){ //Return something if it's not a reference;
        //Find the values first and load them.

        regn = (memory[address1] + memory[address2]);
        //Will need to fix this later, it's double temporarily. May need to be casted.
//more eff to just put reg1 reg2 in private or per function??
        return regn;
    }

    void jump(){
    }
};
CPU oneCPU;

class Memory{
private:
    static int address1;

public:
    Memory(int value,int address)
    {
        address1++;
        address = address1;
        oneCPU.store(value,address1);
    }

    void allocateMemory(int value,int &address){
        address1++;
        address = address1;
        oneCPU.store(value,address1);
    }

};
int Memory::address1 = 0;

//Memory oneMemory;
namespace tpp{

    double add(double val1, double val2){
//        oneCPU.store(val1,);
//        oneCPU.store(val2);

        return (oneCPU.add(0,1));
    }

    template <class T>
    void disp(T val){
        std::cout<<val;
    }
}

class Integer{
    friend void operator<<(std::ostream& o, Integer one);
//    friend Integer operator+(Integer one,Integer two);
    template <class T>
    friend T operator+(T one,T two);
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
    int x = 4;

    int y = 34;
    float t = 23.231;
    int z;
    Integer test1 =25;
    test1 = test1 + test1;
    z = tpp::add(t,y);

    tpp::disp(test1);

}

void operator<<(std::ostream& o, Integer i){o<<i.val;}

template <class T>
T operator+(T one,T two){
    //I will need to replace with CPU add soon.
    T three;
    three.val = one.val + two.val;
    return three.val;
}