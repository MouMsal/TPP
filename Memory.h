
#ifndef TPP_MEMORY_H
#define TPP_MEMORY_H
#include <cstddef>
#include <vector>
class Memory{

private:
    static size_t address1; //Learned to use size_t from chatgpt
    std::vector<char>register1;

public:
    ~Memory();
    Memory();
    template <class T>
    void allocateMemory(T val, size_t &address);
    template<class T> T& getVal(size_t address);
    void resize(size_t size);
};



#endif //TPP_MEMORY_H
