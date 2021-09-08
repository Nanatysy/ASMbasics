; char *strdup(const char *s1)
; rdi - s1

				global	_ft_strdup
				extern	_ft_strlen
				extern	_ft_strcpy
				extern	_malloc
				extern	___error
_ft_strdup:		call	_ft_strlen
				inc		rax
				push	rdi
				mov		rdi, rax
				call	_malloc
				pop		rdi
				cmp		rax, byte 0
				je		error
				mov		rsi, rdi
				mov		rdi, rax
				call	_ft_strcpy
				ret
error:			call	___error
				mov		rdx, rax
				mov		[rdx], byte 12
				mov		rax, 0
				ret
