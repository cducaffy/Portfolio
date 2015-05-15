/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarriga <mdarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 17:28:21 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/18 18:54:31 by mdarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS_H
# define LIBFTS_H

# include <string.h>

char	*ft_strcat(char *s1, const char *s2);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_strlen(char *s);
int		ft_puts(const char *s);
char	*ft_strdup(const char *s1);
void	ft_cat(int fd);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_isblank(int c);
int		ft_isspace(int c);
void	ft_putstr(char *str);
char	*ft_strnew(size_t size);
void	ft_strclr(char *s);

#endif
