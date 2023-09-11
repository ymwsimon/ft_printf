/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:53:49 by mayeung           #+#    #+#             */
/*   Updated: 2023/09/11 17:53:49 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_mergenfreestr(char *org, char *tmp)
{
	char	*res;

	res = 0;
	res = ft_strjoin(org, tmp);
	free(org);
	free(tmp);
	return (res);
}

char	*ft_buildstr(char t, va_list ap)
{
	char	*s;

	if (t == 'c')
		return (ft_ctoa(va_arg(ap, int)));
	else if (t == 'i' || t == 'd')
		return (ft_itoa(va_arg(ap, int)));
	else if (t == 'p')
		return (ft_adrtoa(va_arg(ap, void *)));
	else if (t == 's')
		return (ft_stoa(va_arg(ap, char *)));
	else if (t == 'u')
		return (ft_utoa(va_arg(ap, int), 1, 10));
	else if (t == 'x' || t == 'X')
	{
		s = ft_utoa(va_arg(ap, int), 1, 16);
		if (t == 'X')
			ft_strtoupper(s);
		return (s);
	}
	else if (t == '%')
		return (ft_percent());
	return (0);
}

int	ft_adduntilper(const char *fmt, char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (fmt[i] && fmt[i] != '%')
		i++;
	tmp = 0;
	tmp = malloc(sizeof(char) * (i + 1));
	tmp = ft_strncpy(tmp, fmt, i);
	tmp[i] = 0;
	*str = ft_mergenfreestr(*str, tmp);
	return (i);
}

int	ft_errorexit(char *str, va_list ap)
{
	free(str);
	va_end(ap);
	return (-1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	char	*str;
	char	*tmp;
	size_t	i;

	str = 0;
	va_start(ap, fmt);
	while (fmt && *fmt)
	{
		i = ft_adduntilper(fmt, &str);
		if (fmt[i])
		{
			if (fmt[i + 1] && ft_validarg(fmt[i + 1]))
			{
				tmp = ft_buildstr(fmt[i + 1], ap);
				str = ft_mergenfreestr(str, tmp);
			}
			else
				return (ft_errorexit(str, ap));
			fmt += 2;
		}
		fmt += i;
	}
	va_end(ap);
	return (ft_printnfree(str));
}
