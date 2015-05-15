;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_puts.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/23 16:14:08 by cducaffy          #+#    #+#              ;
;    Updated: 2015/03/23 19:24:38 by cducaffy         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global _ft_puts

section .data
	line db 10
	buff: db "(null)", 10
	size equ $ - buff

section .text

_ft_puts:
	mov r8, rdi

loop:
	cmp rdi, 0
	je null
	cmp [r8], byte 0
	je end
	mov rdi, 1
	mov rsi, r8
	mov rdx, 1
	mov rax, 0x2000004
	syscall
	inc r8
	jmp loop

end:
	push 10
	mov rsi, rsp
	mov rdi, 1
	mov rdx, 1
	mov rax, 0x2000004
	syscall
	pop rax
	ret

null:
	lea rsi, [rel buff]
	mov rdi, 1
	mov rdx, size
	mov rax, 0x2000004
	syscall
	ret