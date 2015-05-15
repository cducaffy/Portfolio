;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalpha.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/19 13:38:26 by cducaffy          #+#    #+#              ;
;    Updated: 2015/03/19 13:38:27 by cducaffy         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global _ft_isalpha

section .text

_ft_isalpha:
	cmp rdi, 65
	jl enderror 
	cmp rdi, 122
	jg enderror
	cmp rdi, 90
	jle end
	cmp rdi, 97
	jge end

enderror:
	mov rax, 0
	ret

end:
	mov rax, 1
	ret
	