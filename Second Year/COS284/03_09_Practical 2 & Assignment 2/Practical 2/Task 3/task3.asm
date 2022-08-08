segment .data
    s1 db "Please input the first number: "
    s2 db "Please input the second number: "
    line db 0xa

segment .bss
    i1 resb 1
    i2 resb 1

segment .text
    global _start

_start:

    call _s1
    call _i1
    call _s2
    call _i2
    call _mover

    mov rax, 1
	mov rdi, 1
	mov rsi, i1
	mov rdx, 1
	syscall

    call _line

    mov rax, 60
    mov rdi, 0
    syscall

_i1:

    mov rax, 0
    mov rdi, 0
    mov rsi, i1
    mov rdx, 2
    syscall
    ret

_i2:

    mov rax, 0
	mov rdi, 0
	mov rsi, i2
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
	mov rsi, s2
	mov rdx, 32
	syscall
    ret

_line:

    mov rax, 1
	mov rdi, 1
	mov rsi, line
	mov rdx, 1
	syscall
    ret

_mover:

    mov rsi, [i1]
	sub rsi, '0'
	mov rdi, [i2]
	sub rdi, '0'
    add rsi, rdi
	add rsi, '0'
	mov [i1], rsi
    ret