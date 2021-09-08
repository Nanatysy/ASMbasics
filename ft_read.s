; ssize_t read(int fildes, void *buf, size_t nbytes)
; rdi - fild
; rsi - buf
; rdx - nbytes

				global	_ft_read
				extern	___error
_ft_read:		mov		rax, 0x02000003 ; system call for read
				syscall
				jc		error
				ret

error:			push	rax
				call	___error
				mov		rdx, rax
				pop		rax
				mov		[rdx], rax
				mov		rax, -1
				ret
