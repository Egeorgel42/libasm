global ft_read
extern __errno_location

ft_read:
	mov rax, 0
	syscall
	cmp rax, -4095	; check for err (between -4095 and -1)
    jae error
	ret

error:
	neg rax
	push rbx
	mov rbx, rax
	call __errno_location
	mov [rax], rbx
	pop rbx
	mov rax, -1
	ret