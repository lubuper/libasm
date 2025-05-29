%define ENOMEM 12

section .text
global	ft_strdup ; char *strdup(const char *s);

extern ft_strlen
extern ft_strcpy
extern malloc
extern __errno_location

ft_strdup:
	push rdi ; save string pointer to stack

	call ft_strlen ; call ft_strlen(rdi) => rax
	inc rax
	mov rdi, rax ; rdi is the new param with the value of rax

	call malloc ; malloc(rdi) => rax
	test rax, rax ; if rax is null jump to error
	je .error

	; now rax has malloc memory, rdi is still the len
	mov rdi, rax ; now rdi has malloc from rax
	pop rsi ; popping the stack to rsi (second param)

	call ft_strcpy ; ft_strcpy(rdi, rsi)
	ret


.error:
	mov edi, ENOMEM ; ENOMEM is a macro in C headers with the value of 12 (not enough memory)
	call __errno_location
	mov dword [rax], ENOMEM ; store 32bit, 12 at *(int *)rax
	pop rdi ; free stack
	xor rax, rax ; clear rax
	ret