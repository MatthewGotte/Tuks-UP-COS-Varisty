section .data
    output db "", 2      
    s1 dq  "Please input a string: ", 10  
    s2 dq "The new string is: "
    ; input db  "", 10

section .bss
    input resb 1000
       
section .text
    global _start

    _start:
        mov  rax, 0x1        
        mov  rdi, 0x1
        mov  rsi, s1     
        mov  rdx, 23              
        syscall   

        mov  rax, 0            
        mov  rdi, 0
        mov  rsi, input     
        mov  rdx, 1000              
        syscall  

    mov eax, input
    mov rcx, 0

    Start:
        cmp byte [eax], 0x0
            jz endloopfunction
            ; cmp byte [eax], 0
            ; je endloopfunction
        
        cmp byte [eax], 32
            jz incCounter

        cmp byte [eax], 90
        jl isUpper
        jmp isLower

        isLower: 
            sub byte [eax], 32
            jmp incCounter
x
        isUpper: 
            add byte [eax], 32
            jmp incCounter   

        incCounter:  
            inc rcx
            add eax, 1
            jmp Start

    endloopfunction:

        sub rcx, 1
        mov [output], rcx

        mov  rdx, 19          
        mov  rsi, qword s2     
        mov  rax, 0x1          
        mov  rdi, 0x1            
        syscall  
        
	    xor rax, rax
	    xor rbx, rbx
	    mov rax, 1
	    mov rdi, 1
	    mov rdx, [output]
        lea rsi, [input]
	    syscall 
  
        mov rax, 60
        xor rdi, rdi
        syscall

