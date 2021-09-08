; rax - туда возращаемое значение
; rdi - там будет лежать строка
; rcx - счетчик

				global	_ft_strlen
_ft_strlen:		xor		rax, rax
check_char:		cmp		[rdi + rax], byte 0
				je		end
				inc		rax
				jmp		check_char
end:			ret
