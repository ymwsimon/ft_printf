/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_gen_asc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:53:37 by mayeung           #+#    #+#             */
/*   Updated: 2023/09/11 17:53:37 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	g_table[] = "0123456789abcdef";

size_t	ft_uint_length(unsigned long int n, int base)
{
	size_t	i;

	i = 1;
	while (n / base)
	{
		n /= base;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t				i;
	int					sign;
	char				*res;
	unsigned long int	t;

	t = n;
	i = ft_uint_length(t * ((n < 0) * -1 + (n >= 0) * 1), 10) + ((n < 0) * 1);
	res = malloc(sizeof(char) * (i + 1));
	res[i] = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		res[0] = '-';
	}
	if (!n)
		res = ft_strncpy(res, "0", 2);
	while (n)
	{
		res[--i] = (n % 10) * sign + '0';
		n /= 10;
	}
	return (res);
}

char	*ft_utoa(unsigned long int n, int trim, int base)
{
	size_t	i;
	char	*res;

	if (trim)
		n = (unsigned int)n;
	i = ft_uint_length(n, base);
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (res);
	res[i] = 0;
	if (!n)
		res = ft_strncpy(res, "0", 2);
	while (n)
	{
		res[i - 1] = g_table[n % base];
		n /= base;
		i--;
	}
	return (res);
}

char	*ft_ctoa(int c)
{
	char	*res;

	res = 0;
	res = malloc(sizeof(char) * 2);
	if (res)
	{
		res[0] = (char)c;
		res[1] = 0;
	}
	return (res);
}

int	ft_printnfree(char *str)
{
	int	i;

	i = 0;
	ft_putstr(str);
	i = ft_strlen(str);
	free(str);
	return (i);
}
