section .data
           ; Reserve space for 10 characters
    s1 dq  "Please enter a string: " ,10
    s2 dq "The length of the string is: ",10
    in1 db  "",0x0a
    num dq "",1
    len dq "",1
    
section .text
    global _start

    _start:

    call messages 

    xor rax, rax
    xor rdx,rdx
    xor rcx,rcx
    mov rdx, in1
    mov rsi,rdx            

looper: 
    cmp byte[rsi],0         
    je ext                
    inc rcx                 
    inc rsi                 
    jmp looper

ext:	  
    ; sub rcx,1
    call calc1

    cmp rax,48
    jz one

    xor rcx,rcx
	xor rax,rax
	xor rbx,rbx
	mov rax,1
	mov rdi,1
	mov rdx, 29
	lea rsi, [s2]
	syscall 

    xor rax,rax
	xor rbx,rbx
    xor rcx,rcx
    xor rdx,rdx
	mov rax,1
	mov rdi,1
	mov rdx, 1
	lea rsi, [num]
	syscall  

    xor rax,rax
	xor rbx,rbx
    xor rcx,rcx
    xor rdx,rdx
	mov rax,1
	mov rdi,1
	mov rdx, 1
	lea rsi, [len]
	syscall 

jmp exitcode

one:

    xor rcx,rcx
	xor rax,rax
	xor rbx,rbx
	mov rax,1
	mov rdi,1
	mov rdx, 29
	lea rsi, [s2]
	syscall 

    xor rdx,rdx
	xor rcx,rcx
	xor rax,rax
	xor rbx,rbx
	mov rax,1
	mov rdi,1
	mov rdx, 1
	lea rsi, [len]
	syscall 

    exitcode:  
        mov rax,60
        xor rdi,rdi
        syscall

messages:
    mov  rax, 0x1              
    mov  rdi, 0x1 
    mov  rsi, qword s1    
    mov  rdx,23              
    syscall    

    mov  rax, 0x0              
    mov  rdi, 0x0
    mov  rsi, in1  
    mov  rdx,132              
    syscall 
    ret

calc1:

    mov rax,rcx
    xor rdx,rdx
    mov r10,10
    div r10
    add rax,'0'
    add rdx,'0'
    mov r11,rax
    mov r12,rdx
    mov [num],r11
    mov [len],r12
    add rcx,1
    xor rdx,rdx
    ret