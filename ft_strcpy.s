global ft_strcpy

ft_strcpy:
	mov rax, rdi;
	mov rcx, 0;

	loop:
	mov BYTE dl, [rsi + rcx];
	mov BYTE [rdi + rcx], dl;
	cmp	BYTE [rsi + rcx], 0;
	je return;
	inc rcx;
	jmp loop;

	return:
	ret;