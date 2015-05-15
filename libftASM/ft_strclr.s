;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strclr.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/24 13:17:45 by cducaffy          #+#    #+#              ;
;    Updated: 2015/03/24 13:17:46 by cducaffy         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global _ft_strclr

extern _ft_strlen
extern _ft_bzero

section .text

_ft_strclr:
	cmp rdi, 0
	je end
	push rdi
	call _ft_strlen
	mov rsi, rax
	pop rdi
	call _ft_bzero

end:
	ret