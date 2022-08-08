section .data
    ; s1 db "Please input the first number: "
    ; s2 db "Please input the second number: "
    ; line db 0xa
    int_1 db "", 2
    s1 db "Please input the first number: ", 0x0a
    s2 db "Please input the second number: ", 0x0a
    int_2 db "aaaaaa", 10
    quotient db "aaaaaa", 10
    remainder db "aaaaaa", 10
    divider dq "aaaaaaa", 32
    point_r db "r", 10
    line db "", 10

section .bss
    ; int_1 resb 8
    ; int_2 resb 8

section .text
    global _start

_start:

    mov rax, 1
    mov rdi, 1
    mov rsi, s1
    mov rdx, 31
    syscall

    mov rax, 0
    mov rdi, 0
    mov rsi, int_1
    mov rdx, 2
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, s2
    mov rdx, 32
    syscall

    mov rax, 0x0
    mov rdi, 0x0
    mov rsi, int_2
    mov rdx, 0x2
    syscall

    movsx r8, byte [int_1]
    movsx r10, byte [int_2]
    sub r8,48
    sub r10,48
    xor rdx,rdx
    mov rax,r8
    mov [remainder] , r10
    div dword [remainder]
    add rax,48
    mov [quotient] , rax
    add rdx,48
    mov [remainder] , rdx

    mov rax, 1
    mov rdi, 1
    mov rsi, quotient
    mov rdx, 1
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, point_r
    mov rdx, 1
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, remainder
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

