;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/23 12:21:52 by cducaffy          #+#    #+#              ;
;    Updated: 2015/03/23 12:38:46 by cducaffy         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global _ft_memcpy

section .text

_ft_memcpy:
	mov rax, rdi

start:
	mov rcx, rdx
	rep movsb
	
end:
	ret