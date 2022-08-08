segment .data
    s1 db "Please input the first number: "; 31
    s2 db "Please input the second number: "; 32
    zero db "0"
    line db 0xa
    int_1 db 0
    int_2 db 0


segment .bss
    ; int_1 resb 8
    ; int_2 resb 8

segment .text
    global _start

_start:

    call _s1
    call _get_i1
    call _s2
    call _get_i2

    ;maths
    mov ah, ah
    mov al, [int_1]
    sub al, [int_2]
    or al, 30h
    mov [int_1], ax
    syscall
    
    ;prints
    ; mov rax, 1
    ; mov rdi, 1
    ; mov rsi, [int_2]
    ; mov rdx, 2
    ; syscall
    mov rax, 1
    mov rdi, 1
    mov rsi, zero
    mov rdx, 1
    syscall
    
    mov rax, 1
    mov rdi, 1
    mov rsi, int_1
    mov rdx, 1
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, line
    mov rdx, 1
    syscall

    ;exit
    mov rax, 60
    xor edi, edi
    syscall

_get_i1:
    
    mov rax, 0
    mov rdi, 0
    mov rsi, int_1
    mov rdx, 2
    syscall
    ret

_get_i2:

    mov rax, 0
    mov rdi, 0
    mov rsi, int_2
    mov rdx, 2
    syscall
    ret

_s1:

    mov rax, 1
	mov rdi, 1
	mov rsi, s1
	mov rdx, 31
	syscall
    ret

_s2:

    mov rax, 1
	mov rdi, 1
	mov rsi, s1
	mov rdx, 31
	syscall
    ret

