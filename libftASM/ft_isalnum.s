;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalnum.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/19 14:50:39 by cducaffy          #+#    #+#              ;
;    Updated: 2015/03/19 14:50:40 by cducaffy         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global _ft_isalnum

section .text

_ft_isalnum:
	cmp rdi, 48
	jl enderror
	cmp rdi, 122
	jg enderror
	cmp rdi, 58
	jl end
	cmp rdi, 96
	jg end
	cmp rdi, 65
	jl enderror
	cmp rdi, 90
	jg enderror

end:
	mov rax, 1
	ret

enderror:
	mov rax, 0
	ret

