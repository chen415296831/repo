	.file	"syscall.c"
	.intel_syntax noprefix
	.text
	.section	.rodata
.LC0:
	.string	"hello world\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	edx, 12
	lea	rsi, .LC0[rip]
	mov	edi, 1
	call	write@PLT
	mov	edi, 0
	call	_exit@PLT
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 8.2.0-7ubuntu1) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
