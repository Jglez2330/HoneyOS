#include "kernel.h"

volatile char* video_text;
void kernel_main(){
    video_text = (volatile char *)0xB8000;

    char* hello = "Hello world! From 32 bits kernel";

    printf(hello);

}

void printf(char* string){
    while (*string != 0x0){
        *video_text++ = *string;
        video_text++;
        string++;
    }
}
