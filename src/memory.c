#include "memory/memory.h"


void* memset(void * ptr, int value, size_t size){

    unsigned char* c_ptr = (unsigned char*)ptr;
    for (int i = 0; i < size; i++){
        c_ptr[i] = (char) value;
    }
    return ptr;

}
