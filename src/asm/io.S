section .asm

global insb
global insw
global outb
global outw

insb:
    push ebp
    mov ebp, esp
   
    xor eax, eax
    mov edx, [ebp + 8] ; is 8 because we stored ebp (4 bytes) and later we had the return address EIP (4bytes)

    in al, dx

    pop ebp
    ret

insw:
    push ebp
    mov ebp, esp

    xor eax, eax
    mov edx, [ebp + 8]

    in ax, dx
    pop ebp
    ret

outb:
    push ebp
    mov ebp, esp

    xor eax, eax
    mov eax, [ebp + 0x08] ; data
    mov edx, [ebp + 0x0C] ; port

    out dx, al

    pop ebp
    ret

outw:
    push ebp
    mov ebp, esp
    
    xor eax, eax
    mov eax, [ebp + 0x08]
    mov edx, [ebp + 0x0C]

    out dx, ax

    pop ebp
    ret

