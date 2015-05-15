;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_cat.s                                           :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/24 13:03:31 by cducaffy          #+#    #+#              ;
;    Updated: 2015/03/24 13:03:31 by cducaffy         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

%define MACH_SYSCALL(nb)    0x2000000 | nb
%define WRITE                4
%define READ                 3

global _ft_cat
section .data

buffer times 255 db 0
bsize equ $ - buffer

section .text

_ft_cat:
	push rbp
	mov rbp, rsp

loop:
	push rdi
	lea rsi, [rel buffer]
	mov rdx, bsize
	mov rax, MACH_SYSCALL(READ)
	syscall
	jc error
	mov rdx, rax
	cmp rax, 0
	je end
	mov rdi, 1
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	jc error
	pop rdi
	jmp loop

error:
	pop rdi
	mov rax, 1
end:
	mov rsp, rbp
	pop rbp
	ret