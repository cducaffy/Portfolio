;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isblank.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/24 13:15:40 by cducaffy          #+#    #+#              ;
;    Updated: 2015/03/24 13:15:41 by cducaffy         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global _ft_isblank

section .text

_ft_isblank:
	cmp rdi, 32
	je end_s
	cmp rdi, 9
	je end_s
	jmp end_f

end_s:
	mov rax, 1
	ret
end_f:
	mov rax, 0
	ret