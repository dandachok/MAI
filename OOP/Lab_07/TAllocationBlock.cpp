#include "TAllocationBlock.hpp"
#include <iostream>

TAllocationBlock::TAllocationBlock(size_t sz, size_t cnt) : size(sz), count(cnt) {
    _used_blocks = (Byte *)malloc(size * count);
    _free_blocks = (void **)malloc(sizeof(void *) * count);
    for(size_t i = 0; i < count; i++) {
        _free_blocks[i] = _used_blocks + i * size;
    }
    free_count = count;
    std::cout << "TAllocationBlock: Memory init" << std::endl;
}

void * TAllocationBlock::allocate() {
    void * result = nullptr;
    if(free_count > 0) {
        result = _free_blocks[free_count - 1];
        free_count--;
        return result;
    }
    else {
        throw std::bad_alloc();
    }
}

void TAllocationBlock::deallocate(void* pointer) {
    _free_blocks[free_count] = pointer;
    free_count++;
}

bool TAllocationBlock::has_free_blocks() {
    return free_count > 0;
}

TAllocationBlock::~TAllocationBlock() {
    delete _free_blocks;
    delete _used_blocks;
}
