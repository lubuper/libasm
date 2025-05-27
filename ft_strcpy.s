section .text
global ft_strcpy ; char *ft_strcpy(char *dest, const char *src);

ft_strcpy:
	mov rax, rdi ; destination pointer saved to return register

.loop:
	mov al, byte [rsi] ; load byte from src (rsi) to al
	mov byte [rdi], al ; store al byte to dst (rdi)
	test al, al ; sets zero flag to 1 if al is == 0. \0 = null = 0
	je .end
	inc rsi ; next src char
	inc rdi ; next dst place
	jmp .loop

.end:
	ret ; return rax that is being used to show dst (rdi)