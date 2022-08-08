section .data
    s1 dq  "Please input an integer: ",0x0a  
    s2 dq "The total sum is: "
    input1 db  ""
    ans db ""
       

section .text
    global _start

    _start:
        call messages
               
    start: 
        cmp byte[rsi],0         
        je ext                
        inc rcx                 
        inc rsi                 
        jmp start

    ext:	  
        sub rcx,1
        mov r8,input1
        mov r9,0
        mov r10,0
        mov r11,1
        mov r12,10
        mov r15,1
        mov r14,0
        mov rax,0
        add r8,rcx
        sub r8,1

    start2:
        cmp rcx,0
        je extit2
        movsx r9,byte [r8]
        sub r9,'0'
        mov rax,r9
        mul r11
        add r10,rax
        mov rax,1
        mov r14,r15

        multiplier2: 
            cmp r14,0
            je endmultiplier2
            sub r14,1
            mul r12
            jmp multiplier2

        endmultiplier2:
            mov r11,rax
            inc r15
            sub rcx,1
            sub r8,1
            jmp start2

    extit2:
        mov r11,0

    start3:
        cmp r10,0
        je ext3
        add r11,r10
        sub r10,1
        jmp start3

    ext3:
        mov r12,0
        mov r15,0
        mov r13,0
        mov rax,r11
        mov r10,10
        mov r9,0
        mov rdx,0
        mov r8,ans
    
    start4:
        xor rdx,rdx
        cmp rax,10
        jl less
        div r10
        inc r9
        jmp start4

    less:
        cmp rax,0
        jz totaljump
        cmp r9,0
        je zerovalue
        mov r12,rax
        add rax,48
        mov [r8],rax
        inc r15
        mov rax,10

        mul1:
            cmp r9,1
            je endMul

            mul r10
            sub r9,1
            jmp mul1

        endMul:
            mul r12
            sub r11,rax
            div r10
            div r12
            cmp rax,r11
            jg addZero
            jmp skip

        addZero:
            inc r8
            add r13,'0'
            mov [r8],r13
            inc r15

              skip:  mov rax,r11
                inc r8
                mov r13,0
                mov r9,0
                jmp start4
                
                zerovalue:
                    cmp r15,0
                    jz this
                    add rax,'0'
                    mov [r8],rax
                    inc r15
                    jmp totaljump

            this:    
                add rax,'0'
                mov [r8],rax
                inc r15
                jmp totaljump

    ; totaljump:

    totaljump:
        mov  rdx,18              
        mov  rsi, qword s2    
        mov  rax, 0x1             
        mov  rdi, 0x1              
        syscall
    
        mov  rdx,r15                
        mov  rsi, dword ans     
        mov  rax, 0x1             
        mov  rdi, 0x1  
        syscall 

exit:
    mov rax,60
    xor rdi,rdi
    syscall

messages:

    mov  rax, 0x1               
    mov  rdi, 0x1  
    mov  rsi, qword s1     
    mov  rdx,25             
    syscall    

    mov  rax, 0x0             
    mov  rdi, 0x0  
    mov  rsi, input1     
    mov  rdx,132       
    syscall  

    mov rdx, input1
    mov rsi,rdx 
    xor rax, rax
    xor rdx,rdx
    xor rcx,rcx

    ret