/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:45:47 by vschneid          #+#    #+#             */
/*   Updated: 2023/09/15 16:13:27 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# ifndef FD
#  define FD 4098
# endif

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *str, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char const *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t destsize);
size_t	strlcpy(char *dest, const char *src, size_t destsize);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char *s1, char *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

char	*get_next_line(int fd);
char	*vs_buff_to_pot(int fd, char *pot_str);
char	*vs_check_line(char *pot_str);
char	*vs_fresh_pot(char *old_pot);
char	*vs_strchr(const char *s, int c);
int		vs_strlen(const char *str);
char	*vs_strjoint(char *left_str, char *buff);

int		ft_printf(const char *fmt, ...);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putnbr(long long int num);
int		ft_printhex_lower(unsigned long long number);
int		ft_printhex_upper(unsigned long long number);
int		ft_hexptr(unsigned long long int num);

#endif
