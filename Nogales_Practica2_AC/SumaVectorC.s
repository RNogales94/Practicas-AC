	.file	"SumaVectoresC.c"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"Faltan n\302\272 componentes del vector"
	.align 8
.LC1:
	.string	"Error en la reserva de espacio para los vectores"
	.align 8
.LC4:
	.string	"Tiempo(seg.):%11.9f\t / Tama\303\261o Vectores:%u\t/ V1[0]+V2[0]=V3[0](%8.6f+%8.6f=%8.6f) V1[%d]+V2[%d]=V3[%d](%8.6f+%8.6f=%8.6f) /\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB18:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	subq	$32, %rsp
	.cfi_def_cfa_offset 80
	cmpl	$1, %edi
	jle	.L15
	movq	8(%rsi), %rdi
	movl	$10, %edx
	xorl	%esi, %esi
	call	strtol
	movl	%eax, %r14d
	movl	%eax, %ebx
	leaq	0(,%r14,8), %r13
	movq	%r13, %rdi
	call	malloc
	movq	%r13, %rdi
	movq	%rax, %rbp
	call	malloc
	movq	%r13, %rdi
	movq	%rax, %r12
	call	malloc
	testq	%r12, %r12
	movq	%rax, %r13
	je	.L3
	testq	%rbp, %rbp
	je	.L3
	testq	%rax, %rax
	je	.L3
	testl	%ebx, %ebx
	.p2align 4,,3
	je	.L16
	cvtsi2sdq	%r14, %xmm1
	xorl	%eax, %eax
	movsd	.LC2(%rip), %xmm3
	mulsd	%xmm3, %xmm1
	.p2align 4,,10
	.p2align 3
.L8:
	cvtsi2sd	%eax, %xmm0
	mulsd	%xmm3, %xmm0
	movapd	%xmm0, %xmm2
	addsd	%xmm1, %xmm2
	movsd	%xmm2, 0(%rbp,%rax,8)
	movapd	%xmm1, %xmm2
	subsd	%xmm0, %xmm2
	movsd	%xmm2, (%r12,%rax,8)
	addq	$1, %rax
	cmpl	%eax, %ebx
	ja	.L8
	movq	%rsp, %rsi
	xorl	%edi, %edi
	call	clock_gettime
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L9:
	movsd	0(%rbp,%rax,8), %xmm0
	addsd	(%r12,%rax,8), %xmm0
	movsd	%xmm0, 0(%r13,%rax,8)
	addq	$1, %rax
	cmpl	%eax, %ebx
	ja	.L9
.L10:
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	16(%rsp), %rcx
	subq	(%rsp), %rcx
	leal	-1(%rbx), %edx
	movsd	0(%r13), %xmm3
	movl	%ebx, %esi
	movl	%edx, %eax
	movsd	(%r12), %xmm2
	movsd	0(%r13,%rax,8), %xmm6
	movl	%edx, %r8d
	cvtsi2sdq	%rcx, %xmm0
	movq	24(%rsp), %rcx
	subq	8(%rsp), %rcx
	movsd	(%r12,%rax,8), %xmm5
	movsd	0(%rbp,%rax,8), %xmm4
	movl	$.LC4, %edi
	movl	$7, %eax
	cvtsi2sdq	%rcx, %xmm1
	movl	%edx, %ecx
	divsd	.LC3(%rip), %xmm1
	addsd	%xmm1, %xmm0
	movsd	0(%rbp), %xmm1
	call	printf
	movq	%rbp, %rdi
	call	free
	movq	%r12, %rdi
	call	free
	movq	%r13, %rdi
	call	free
	addq	$32, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
.L16:
	.cfi_restore_state
	movq	%rsp, %rsi
	xorl	%edi, %edi
	call	clock_gettime
	jmp	.L10
.L3:
	movl	$.LC1, %edi
	call	puts
	movl	$-2, %edi
	call	exit
.L15:
	movl	$.LC0, %edi
	call	puts
	orl	$-1, %edi
	call	exit
	.cfi_endproc
.LFE18:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC2:
	.long	2576980378
	.long	1069128089
	.align 8
.LC3:
	.long	0
	.long	1104006501
	.ident	"GCC: (GNU) 4.6.3 20120306 (Red Hat 4.6.3-2)"
	.section	.note.GNU-stack,"",@progbits
