;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strnew.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/24 13:18:01 by cducaffy          #+#    #+#              ;
;    Updated: 2015/03/24 13:18:02 by cducaffy         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global _ft_strnew
extern _malloc
extern _ft_memset

section .text

_ft_strnew:
	push rdi
	call _malloc
	mov rdi, rax
	mov rsi, 0
	pop rdx
	call _ft_memset

end:
	ret