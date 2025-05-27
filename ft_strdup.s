section .text
global	ft_strdup ; char *strdup(const char *s);

extern ft_strlen
extern ft_strcpy
extern malloc

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
	mov edi, ENOMEM
	call __errno_location
	mov dword [rax], ENOMEM
	pop rdi ; free stack
	xor rax, rax ; clear rax
	ret