section .data
    linebreak db "",8      
    s1 dq  "Please input a string: ", 10  
    s2 dq "The new string is: "
    input db  "", 10
       

section .text
    global _start

    _start:
        call messages

    Start:
        cmp byte [r8], 0
        jz endloopfunction
        
        cmp byte [r8], 32
        jz incCounter

        cmp byte [r8], 90
        jl isUpper
        jmp isLower

        isLower: 
            sub byte [r8], 32
            jmp incCounter

        isUpper: 
            add byte [r8], 32
            jmp incCounter   

        incCounter:  
            inc rcx
            add r8, 1
            jmp Start

    endloopfunction:

        sub rcx, 1
        mov [linebreak], rcx

        mov  rdx,19          
        mov  rsi, qword s2     
        mov  rax, 0x1          
        mov  rdi, 0x1            
        syscall  
        
	    xor rax, rax
	    xor rbx, rbx
	    mov rax, 1
	    mov rdi, 1
	    mov rdx, [linebreak]
        lea rsi, [input]
	    syscall 
  
        mov rax, 60
        xor rdi, rdi
        syscall

messages:
    mov  rax, 0x1        
    mov  rdi, 0x1
    mov  rsi, qword s1     
    mov  rdx, 23              
    syscall   

    mov  rax, 0            
    mov  rdi, 0
    mov  rsi, input     
    mov  rdx, 132              
    syscall  

    mov r8, input
    mov rcx, 0
    ret