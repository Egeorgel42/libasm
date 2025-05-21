global ft_strdup
extern __errno_location
extern malloc

ft_strdup:
	push rbx
	mov rbx, -1

loop:
	inc rbx
	cmp BYTE [rdi + rbx], 0
	jne loop

malloc_call:
	push rdi
	mov rdi, rbx
	inc rdi
	call malloc
	pop rdi
	cmp rax, 0
	je return
	mov rsi, 0

copy:
	cmp rbx, rsi
	jb return
	mov dl, [rdi + rsi]
	mov [rax + rsi], dl
	inc rsi
	jmp copy

return:
	pop rbx
	ret