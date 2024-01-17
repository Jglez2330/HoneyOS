section .asm

global load_idt
global disable_interrupt
global no_interrupt
global enable_interrupt
extern no_interrupt_handler


load_idt:
    push ebp
    mov ebp, esp
  
    mov ebx, [ebp + 8]
    lidt [ebx]

    
    pop ebp
    ret

no_interrupt:
    cli
    pushad
    call no_interrupt_handler
    popad
    sti
    iret

enable_interrupt:
    sti
    ret
disable_interrupt:
    cli 
    ret
