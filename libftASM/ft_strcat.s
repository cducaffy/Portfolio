;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcat.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/19 15:27:48 by cducaffy          #+#    #+#              ;
;    Updated: 2015/03/19 15:27:49 by cducaffy         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global _ft_strcat

section .text

_ft_strcat:
	mov rax, rdi

loop:
	cmp byte[rdi], 0
	jz copy
	inc rdi
	jmp loop

copy:
	cmp byte[rsi], 0
	jz end
	movsb
	jmp copy


end:
	mov [rdi], byte 0
	ret