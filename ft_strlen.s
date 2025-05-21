section .text
global ft_strlen

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