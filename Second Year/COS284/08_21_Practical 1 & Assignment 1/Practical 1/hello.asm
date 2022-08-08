section .data
    storage db  "AAAABB"       ; Reserve space for 10 characters
    prompt db  "Please input your student number: ",10
    string3 db  "Your student number is: u",10

section .text
    global _start

    _start:

        mov  rdx, 0x22               ; length of string is 13 bytes
        mov  rsi, dword prompt     ; set rsi to pointer to string
        mov  rax, 0x1               ; syscall 1 is write
        mov  rdi, 0x1               ; stdout has a file descriptor of 1
        syscall                     ; make the system call

        mov  rdx, 0xa               ; length of string is 10 bytes
        mov  rsi, dword storage     ; set rsi to pointer to string
        mov  rax, 0x0               ; syscall 0 is read
        mov  rdi, 0x0               ; stdin has a file descriptor of 0
        syscall                     ; make the system call

        mov  rdx, 0x19               ; length of string is 13 bytes
        mov  rsi, dword string3     ; set rsi to pointer to string
        mov  rax, 0x1               ; syscall 1 is write
        mov  rdi, 0x1               ; stdout has a file descriptor of 1
        syscall                     ; make the system call

        mov  rdx, 0x8               ; length of string is 10 bytes
        mov  rsi, dword storage    ; set rsi to pointer to string
        mov  rax, 0x1               ; syscall 1 is write
        mov  rdi, 0x1               ; stdout has a file descriptor of 1
        syscall                     ; make the system call

        mov eax,60
        xor edi,edi
        syscall
        ;mov  rax, 0x3c              ; syscall 3c is exit
        ;syscall                     ; make the system call