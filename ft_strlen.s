section .text
global ft_strlen ; size_t ft_strlen(const char *s1)

ft_strlen:
	xor rcx, rcx

.loop:
	mov al, byte [rdi + rcx]
	test al, al
	je .end
	inc rcx
	jmp .loop

.end:
	mov rax, rcx
	ret