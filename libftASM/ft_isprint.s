;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isprint.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/19 15:09:20 by cducaffy          #+#    #+#              ;
;    Updated: 2015/03/19 15:09:20 by cducaffy         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global _ft_isprint

section .text

_ft_isprint:
	cmp rdi, 32
	jl enderror 
	cmp rdi, 126
	jg enderror

end:
	mov rax, 1
	ret

enderror:
	mov rax, 0
	ret