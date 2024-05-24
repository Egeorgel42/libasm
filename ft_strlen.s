global ft_strlen

ft_strlen:
	mov rax, 0;

	loop:
	cmp BYTE [rdi + rax], 0;
	je	return;
	inc rax;
	jmp loop;

	return:
	ret