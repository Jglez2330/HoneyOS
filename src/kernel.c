#include "kernel.h"
#include "string.h"
#include "idt/idt.h"
#include "io/io.h"

void io_wait(){
   outb( 0x80, 0); 
}
void remap_pic(){
    outb(0x20, 0x11);
    io_wait();
    outb(0xA0, 0x11);
    io_wait();
    outb(0x21, 0x20);
    io_wait();
    outb(0xA1, 0x28);
    io_wait();
    outb(0x21, 0x04);
    io_wait();
    outb(0xA1, 0x02);
    io_wait();
    outb(0x21, 0x01);
    io_wait();
    outb(0xA1, 0x01);
}
void kernel_main(){
    
    //remap_pic();
    char* hello = "Hello world! From 32 bits kernel";

    printf(hello);
    idt_init();
    enable_interrupt();


}


