section .data
    s1 db "Please input a 5 digit number: "
    s2 db "This is the number you are looking for: "
    line db "", 10

section .bss
    num resb 5

section .text
    global _start

_start:

    call _print_s1
    call _get_num
    mov rax, 1
    mov rdi, 1
    mov rsi, line
    mov rdx, 1
    syscall
    call _print_s2
    call _print_num

    mov rax, 1
    mov rdi, 1
    mov rsi, line
    mov rdx, 1
    syscall

    mov rax, 60
    mov rdi, 0
    syscall

_print_s1:

    mov rax, 1
    mov rdi, 1
    mov rsi, s1
    mov rdx, 31
    syscall
    ret

_print_s2:

    mov rax, 1
    mov rdi, 1
    mov rsi, s2
    mov rdx, 40
    syscall
    ret

_print_num:

    mov rax, 1
    mov rdi, 1
    mov rsi, num
    mov rdx, 5
    syscall
    ret

_get_num:

    mov rax, 0
    mov rdi, 0
    mov rsi, num
    mov rdx, 16
    syscall
    ret

; segment .data
;   s1 db "Please input a 5 digit number: "
;   s2 db "This is the number you are looking for: "
;   line db "",10

; segment .bss
;   ot resb 4

; segment .text
;   global _start

; _start:

;   mov rax, 1
;   mov rdi, 1
;   mov rsi, s1
;   mov rdx, 31
;   syscall

;   mov rax, 0
;   mov rdi, 0
;   mov rsi, ot
;   mov rdx, 5
;   syscall

;   mov rax, 1
;   mov rdi, 1
;   mov rsi, s2
;   mov rdx, 40
;   syscall

;   mov rax, 1
;   mov rdi, 1
;   mov rsi, ot
;   mov rdx, 5
;   syscall

;   mov rax, 1
;   mov rdi, 1
;   mov rsi, line
;   mov rdx, 1
;   syscall

;   mov rax, 60
;   mov rdi, 0
;   syscall

  