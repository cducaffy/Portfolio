;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/19 15:30:51 by cducaffy          #+#    #+#              ;
;    Updated: 2015/03/23 15:14:39 by cducaffy         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global _ft_strlen

section .text

_ft_strlen:
	cmp rdi, 0
	je null
	push rbp
	mov rbp, rsp
	mov al, 0
	mov rcx, -1
	repne scasb
	not rcx
	sub rcx, 1

	mov rax, rcx
	mov rsp, rbp
	pop rbp
	ret
	
null:
	mov rax, 0
	ret
	
	