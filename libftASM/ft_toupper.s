;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_toupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/19 15:24:09 by cducaffy          #+#    #+#              ;
;    Updated: 2015/03/19 15:24:12 by cducaffy         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global _ft_toupper

section .text

_ft_toupper:
	cmp rdi, 97
	jge case1
	cmp rdi, 122
	jle case2
	jmp end

case1:
	cmp rdi, 122
	jle toupper
	jmp end

case2:
	cmp rdi, 97
	jge toupper
	jmp end

toupper:
	sub rdi, 32
	jmp end


end:
	mov rax, rdi
	ret