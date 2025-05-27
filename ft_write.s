section .text
global ft_write ; ssize_t ft_write(int fd, const void buff[count], size_t count)

extern __errno_location

ft_write:
	mov rax, 1 ; syscall number for write in linux x86_64, on Mac is 0x2000004
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