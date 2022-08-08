section .data
    s1 db "Please input the first number: "
    s2 db "Please input the second number: "
    line db 0xa

section .bss
    int_1 resb 8
    int_2 resb 8

section .text
    global _start

_start:

    ;get
    call _s1
    call _get_i1
    call _s2
    call _get_i2
    ;math
    mov rsi, [int_1]
	sub rsi, '0'
	mov rdi, [int_2]
	sub rdi, '0'
	mov rax, rsi
	mul rdi
	mov r8, 10
	xor rdx, rdx
	div r8
	add rax, '0'
	mov [int_1], rax
	add rdx, '0'
	mov [int_2], rdx
    ;prints
    call _print
    ;exit
    mov rax, 60
    xor edi, edi
    syscall

_print:

    mov rax, 1
    mov rdi, 1
    mov rsi, int_1
    mov rdx, 1
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, int_2
    mov rdx, 1
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, line
    mov rdx, 1
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
	mov rsi, s2
	mov rdx, 32
	syscall
    ret

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