/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:53:52 by mayeung           #+#    #+#             */
/*   Updated: 2023/09/11 17:53:53 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

size_t	ft_strlen(char *s);

char	*ft_strncpy(char *dest, const char *src, size_t n);

char	*ft_strdup(char *s);

char	*ft_strjoin(char *s1, char *s2);

void	ft_putstr(char *s);

size_t	ft_uint_length(unsigned long int n, int base);

char	*ft_itoa(int n);

char	*ft_utoa(unsigned long int n, int trim, int base);

char	*ft_ctoa(int c);

void	ft_strtoupper(char *s);

char	*ft_percent(void);

char	*ft_adrtoa(void *adr);

char	*ft_stoa(char *str);

int		ft_validarg(char c);

int		ft_printnfree(char *str);

char	*ft_mergenfreestr(char *org, char *tmp);

char	*ft_buildstr(char t, va_list ap);

int		ft_adduntilper(const char *fmt, char **str);

int		ft_errorexit(char *str, va_list ap);

int		ft_printf(const char *fmt, ...);

#endif
