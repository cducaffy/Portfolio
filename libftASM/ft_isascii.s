;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isascii.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/19 15:06:52 by cducaffy          #+#    #+#              ;
;    Updated: 2015/03/19 15:06:52 by cducaffy         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global _ft_isascii

section .text

_ft_isascii:
	cmp rdi, 0
	jl enderror 
	cmp rdi, 127
	jg enderror

end:
	mov rax, 1
	ret

enderror:
	mov rax, 0
	ret