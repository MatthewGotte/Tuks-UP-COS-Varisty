section .data
	s1 db "Please input the first number: "; 31
	s2 db "Please input the second number: "; 32
	line db 0xa

section .bss
	i1 resb 8
	i2 resb 8

section .text
	global _start

_start:
	;inputs
	call _s1
	call _get_i1
	call _s2
	call _get_i2
	;calculations
	mov rsi, [i1]
	sub rsi, '0'
	mov rdi, [i2]
	sub rdi, '0'
	add rsi, rdi
	mov [i1], rsi
	mov rax, rsi
	mov r8, 10
	xor rdx, rdx
	div r8
	add rax, '0'
	mov [i1], rax
	add rdx, '0'
	mov [i2], rdx
	;prints
	call _print_i1
	call _print_i2
	call _line
	;exit
	mov rax, 60
	xor edi, edi
	syscall

_print_i1:

	mov rax, 1
	mov rdi, 1
	mov rsi, i1
	mov rdx, 1
	syscall
	ret

_print_i2:

	mov rax, 1
	mov rdi, 1
	mov rsi, i2
	mov rdx, 1
	syscall
	ret

_line:

	mov rax, 1
	mov rdi, 1
	mov rsi, line
	mov rdx, 1
	syscall
	ret

_get_i1:

	mov rax, 0
	mov rdi, 0
	mov rsi, i1
	mov rdx, 2
	syscall
	ret

_get_i2:

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