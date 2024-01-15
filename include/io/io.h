#ifndef _IO_H
#define _IO_H

unsigned char insb(unsigned short port);
unsigned char insw(unsigned short port);


void outb(unsigned short port, unsigned char data);
void outw(unsigned short port, unsigned char data);


#endif

