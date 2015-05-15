;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isspace.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/24 13:15:56 by cducaffy          #+#    #+#              ;
;    Updated: 2015/03/24 13:15:57 by cducaffy         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global _ft_isspace

section .text

_ft_isspace:
	cmp rdi, 32
	je end_s
	cmp rdi, 9
	je end_s
	cmp rdi, 13
	je end_s
	cmp rdi, 11
	je end_s
	cmp rdi, 12
	je end_s
	cmp rdi, 10
	je end_s
	jmp end_f

end_s:
	mov rax, 1
	ret
end_f:
	mov rax, 0
	ret