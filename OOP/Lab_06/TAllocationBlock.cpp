#include "TAllocationBlock.hpp"
#include <iostream>

TAllocationBlock::TAllocationBlock(size_t sz, size_t cnt) : size(sz), count(cnt) {
    _used_blocks = (Byte *)malloc(size * count);

    for(size_t i = 0; i < count; i++) {
        void* ptr = (void *)malloc(sizeof(void *));
        ptr = _used_blocks + i * size;
        _free_blocks.Push(ptr);
    }
    free_count = count;
    std::cout << "TAllocationBlock: Memory init" << std::endl;
}

void * TAllocationBlock::allocate() {
    void * result = nullptr;
    if(free_count > 0) {
        result = _free_blocks.Pop();
        free_count--;
        return result;
    }
    else {
        throw std::bad_alloc();
    }
}

void TAllocationBlock::deallocate(void* pointer) {
    _free_blocks.Push(pointer);
    free_count++;
}

bool TAllocationBlock::has_free_blocks() {
    return free_count > 0;
}

TAllocationBlock::~TAllocationBlock() {
    while(_free_blocks.IsEmpty()) {
        _free_blocks.Pop();
    }
    delete _used_blocks;
}
