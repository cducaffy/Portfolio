;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_putstr.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/24 13:18:22 by cducaffy          #+#    #+#              ;
;    Updated: 2015/03/24 13:18:23 by cducaffy         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

%define MACH_SYSCALL(nb)    0x2000000 | nb
%define WRITE                4

global _ft_putstr
extern _ft_strlen

section .data
buff: db "(null)"
size equ $ - buff

section .text

_ft_putstr:
	cmp rdi, 0
	je null
	mov rsi, rdi
	call _ft_strlen
	mov rdx, rax
	mov rdi, 1
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	jmp end

null:
	lea rsi, [rel buff]
	mov rdi, 1
	mov rdx, size
	mov rax, MACH_SYSCALL(WRITE)
	syscall

end:
	ret