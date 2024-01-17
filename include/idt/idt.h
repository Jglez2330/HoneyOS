#ifndef _IDT_H
#define _IDT_H

#include <stdint.h>
typedef struct{
    uint16_t size;
    uint32_t offset;

}__attribute__((packed)) idtr_descriptor;

typedef struct{
    uint16_t offset_1;
    uint16_t selector;
    uint8_t  reserved;
    uint8_t  type_attributes;
    uint16_t offset_2;
}__attribute__((packed)) dtr_descriptor;

void idt_set(uint8_t index, void* handler_address);
void idt_init();
void enable_interrupt();
void disable_interrupt();
#endif //_IDT_H
