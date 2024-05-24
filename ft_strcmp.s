global ft_strcmp

ft_strcmp:
	mov rcx, 0;

	loop:
	mov dl, [rsi + rcx];
	cmp BYTE [rdi + rcx], dl;
	jne return;
	cmp BYTE [rdi + rcx], 0;
	je return;
	inc rcx;
	jmp loop;

	return:
	mov dl, [rdi + rcx];
	sub dl, [rsi + rcx];
	movsx rax, dl;
	ret;