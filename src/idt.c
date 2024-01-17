#include "idt/idt.h"
#include "string.h"
#include "memory/memory.h"
#include "io/io.h"
#include "config/config.h"
dtr_descriptor interrupts[256];
idtr_descriptor descriptor;

extern void no_interrupt();
extern void load_idt(idtr_descriptor* descriptor);
extern void enable_interrupt();
extern void disable_interrupt();

void no_interrupt_handler()
{
    outb(0x20, 0x20);
}
void idt_zero(){
    printf("Zero divisoon int");
}

void idt_init(){

    memset(&interrupts, 0, sizeof(dtr_descriptor)*256);
    memset(&descriptor, 0, sizeof(idtr_descriptor));

    descriptor.size = sizeof(dtr_descriptor)*256 - 1;
    descriptor.offset  = (uint32_t)&interrupts;

    for (int i =0; i < 256; i++){
        idt_set(i, no_interrupt);
    }
    idt_set(0x0, idt_zero);
    load_idt(&descriptor);
}

void idt_set(uint8_t index, void* handler_address){
    dtr_descriptor* interrupt = &interrupts[index];


    interrupt->offset_1 = (uint32_t)handler_address&0x0000FFFF; 
    interrupt->selector = CODE_SELECTOR;
    interrupt->reserved = 0x0;
    interrupt->type_attributes = 0xEE;
    interrupt->offset_2 = (uint32_t)handler_address>>0x10;
}



