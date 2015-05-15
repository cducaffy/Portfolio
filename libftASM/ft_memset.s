;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memset.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/23 12:43:02 by cducaffy          #+#    #+#              ;
;    Updated: 2015/03/23 12:53:42 by cducaffy         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global _ft_memset

section .text

_ft_memset:
	mov rax, rdi

start:
	mov rcx, rdx
	rep stosb
	
end:
	ret