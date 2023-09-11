/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:53:46 by mayeung           #+#    #+#             */
/*   Updated: 2023/09/11 17:53:47 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	if (dest && src && n)
	{
		i = 0;
		while (src[i] && i < n)
		{
			dest[i] = src[i];
			i++;
		}
		while (i < n)
			dest[i++] = 0;
	}
	return (dest);
}

char	*ft_strdup(char *s)
{
	char	*res;
	size_t	i;

	res = 0;
	if (s)
	{
		res = malloc(ft_strlen(s) + 1);
		i = 0;
		while (s[i])
		{
			res[i] = s[i];
			i++;
		}
		res[i] = 0;
	}
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = 0;
	return (res);
}

void	ft_putstr(char *s)
{
	size_t	len;

	len = 0;
	len = ft_strlen(s);
	write(1, s, len);
}
