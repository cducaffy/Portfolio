;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isdigit.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/19 14:45:10 by cducaffy          #+#    #+#              ;
;    Updated: 2015/03/19 14:45:11 by cducaffy         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global _ft_isdigit

section .text

_ft_isdigit:
	cmp rdi, 48
	jl enderror 
	cmp rdi, 57
	jg enderror

end:
	mov rax, 1
	ret

enderror:
	mov rax, 0
	ret
