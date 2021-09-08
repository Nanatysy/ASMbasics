; char *strcpy(char *dst, const char *src)
; rdi - dst
; rsi - src

				global	_ft_strcpy
_ft_strcpy:		xor		rcx, rcx
				xor		rdx, rdx
copy:			mov		dl, [rsi + rcx]
				mov		[rdi + rcx], dl
				cmp		dl, 0
				je		end
				inc		rcx
				jmp		copy
end:			mov		rax, rdi
				ret
