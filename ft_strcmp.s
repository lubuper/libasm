section .text
global ft_strcmp

ft_strcmp:
	xor rcx, rcx

.loop:
	movzx eax, byte [rdi + rcx]
	movzx r8d, byte [rsi + rcx]
	cmp al, r8b ; compare the 8bit lower part of rax with the 8bit lower part of r8 (we are only comparing one char at a time)
	jne .diff
	test al, al ; bitwise AND, setting the CPU Zero Flag (ZF)
	je .equal
	inc rcx
	jmp .loop
	
.diff:
	movzx eax, al
	movzx ecx, r8b
	sub eax, ecx
	ret

.equal:
	xor eax, eax
	ret
	