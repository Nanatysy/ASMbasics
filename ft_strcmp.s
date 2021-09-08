; int strcmp(const char *s1, const char *s2)
; s1 - rdi
; s2 - rsi

				global	_ft_strcmp
_ft_strcmp:		xor		rcx, rcx
				xor		rax, rax
				xor		rdx, rdx
compare:		mov		al, [rdi + rcx]
				cmp		al, [rsi + rcx]
				jne		end
				cmp		al, 0
				je		end
				inc		rcx
				jmp		compare
end:			mov		dl, [rsi + rcx]
				sub		rax, rdx
				ret
