;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cducaffy <marvin@42.fr>                    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/03/23 15:10:15 by cducaffy          #+#    #+#              ;
;    Updated: 2015/03/23 16:10:39 by cducaffy         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

global _ft_strdup

extern _ft_strlen
extern _malloc
	
section .text

_ft_strdup:
	enter 0, 0
	
	cmp rdi, 0
	je null
	
	push rdi
	call _ft_strlen
	mov rcx, rax
	push rcx
	mov rdi, rax
	call _malloc
	jc end
	pop rcx
	pop rsi
	mov rdi, rax
	cld
	rep movsb
	
end:
	leave
	ret

null:
	mov rax, 0
	ret
	