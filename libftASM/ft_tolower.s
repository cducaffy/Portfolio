;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_tolower.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/19 15:13:19 by cducaffy          #+#    #+#              ;
;    Updated: 2015/03/19 15:13:20 by cducaffy         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global _ft_tolower

section .text

_ft_tolower:
	cmp rdi, 65
	jge case1
	cmp rdi, 90
	jle case2
	jmp end

case1:
	cmp rdi, 90
	jle tolower
	jmp end

case2:
	cmp rdi, 65
	jge tolower
	jmp end

tolower:
	add rdi, 32
	jmp end


end:
	mov rax, rdi
	ret