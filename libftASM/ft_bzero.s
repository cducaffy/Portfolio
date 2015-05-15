;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_bzero.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/19 12:46:26 by cducaffy          #+#    #+#              ;
;    Updated: 2015/03/19 12:46:26 by cducaffy         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global _ft_bzero

section .text

_ft_bzero:
	cmp rsi, 0
	je end
	mov [rdi], byte 0
	dec rsi
	inc rdi
	jmp _ft_bzero

end:
	ret
