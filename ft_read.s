section .text
global ft_read ; ssize_t ft_read(int fd, void *buff, size_t count)

ft_write:
	mov rax, 0 ; syscall number for read in linux x86_64, on Mac is 0x2000004
	syscall
	jc .error
	ret

.error:
	neg rax ; -rax to get positive errno
	mov r8, rax
	call __errno_location
	mov [rax], r8d ; r8d for 32bit
	mov rax, -1
	ret