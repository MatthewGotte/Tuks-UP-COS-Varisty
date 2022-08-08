section .data
    s1 db "Please input a lowercase character: " ;36
    s2 db "In uppercase: " ;14
    i1 db 32

section .bss
    c resb 16

section .text
    global _start

_start:

    call _print_s1
    call _get_c
    call _print_s2
    call _to_upper
    call _print_c
    mov rax, 60
    mov rdi, 0
    syscall

_to_upper:

    sub byte[c], 32
    syscall
    ret

_print_s1:

    mov rax, 1
    mov rdi, 1
    mov rsi, s1
    mov rdx, 36
    syscall
    ret

_print_s2:

    mov rax, 1
    mov rdi, 1
    mov rsi, s2
    mov rdx, 14
    syscall
    ret

_get_c:

    mov rax, 0
    mov rdi, 0
    mov rsi, c
    mov rdx, 16
    syscall
    ret

_print_c:

    mov rax, 1
    mov rdi, 1
    mov rsi, c
    mov rdx, 2
    syscall
    ret
