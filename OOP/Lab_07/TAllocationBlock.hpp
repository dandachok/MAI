#ifndef TALLOCATIONBLOCK_HPP
#define TALLOCATIONBLOCK_HPP

#include <iostream>
#include <cstdlib>

typedef unsigned char Byte;

class TAllocationBlock {
public:
    TAllocationBlock(size_t size, size_t count);
    void* allocate();
    void deallocate(void* pointer);
    bool has_free_blocks();

    virtual ~TAllocationBlock();
private:
    size_t size;
    size_t count;

    Byte * _used_blocks;
    void ** _free_blocks; 

    size_t free_count;
};


#endif
