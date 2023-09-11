/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_gen_asc2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:53:43 by mayeung           #+#    #+#             */
/*   Updated: 2023/09/11 17:53:43 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strtoupper(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 'a' - 'A';
		i++;
	}
}

char	*ft_percent(void)
{
	char	*res;

	res = 0;
	res = malloc(sizeof(char) * 2);
	if (res)
	{
		res[0] = '%';
		res[1] = 0;
	}
	return (res);
}

char	*ft_adrtoa(void *adr)
{
	unsigned long int	n;
	char				*res;
	char				*pre;

	if (!adr)
	{
		res = malloc(sizeof(char) * 6);
		res = ft_strncpy(res, "(nil)", 6);
		return (res);
	}
	n = (unsigned long int) adr;
	pre = malloc(sizeof(char) * 3);
	pre[0] = '0';
	pre[1] = 'x';
	pre[2] = 0;
	res = ft_utoa(n, 0, 16);
	res = ft_mergenfreestr(pre, res);
	return (res);
}

int	ft_validarg(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

char	*ft_stoa(char *str)
{
	char	*res;

	if (str)
		return (ft_strdup(str));
	res = malloc(sizeof(char) * 7);
	res = ft_strncpy(res, "(null)", 7);
	return (res);
}	
