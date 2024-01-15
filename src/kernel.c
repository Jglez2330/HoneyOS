#include "kernel.h"
#include "string.h"
#include "idt/idt.h"
void kernel_main(){

    char* hello = "Hello world! From 32 bits kernel";

    printf(hello);
    idt_init();
    for (int i = 0; i <2;i++){
        int result = i/i;
        result++;
    }

}


