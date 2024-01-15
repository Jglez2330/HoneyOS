#include "string.h"
volatile char* video_text;
void printf(char* string){
    video_text = (volatile char *)0xB8000;
    while (*string != 0x0){
        *video_text++ = *string;
        video_text++;
        string++;
    }
}
