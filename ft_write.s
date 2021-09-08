; ssize_t write(int fildes, const void *buf, size_t nbytes)
; rdi - fild
; rsi - buf
; rdx - nbytes 

				global	_ft_write
				extern	___error
_ft_write:		push	rdx
				mov		rax, 0x02000004 ; system call for write
				syscall
				pop		rdx
				jc		error 			; jump if carry flag = 1 (error)
				mov		rax, rdx
				ret
error:
				push	rax
				call	___error
				mov		rdx, rax
				pop		rax
				mov		[rdx], rax
				mov		rax, -1	
				ret
				