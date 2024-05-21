/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:05:29 by vsinagl           #+#    #+#             */
/*   Updated: 2023/12/03 23:02:49 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strchr_m(const char *s, int c)
{
	char	*res;
	size_t	i;

	res = (char *)s;
	if (c > 127)
		return (0);
	i = 0;
	while (res[i] != '\0')
	{
		if (res[i] == c)
			return (++i);
		i++;
	}
	if (res[i] == c)
		return (++i);
	return (0);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*p_dest;
	unsigned char		*p_src;
	size_t				i;

	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (dest);
	if (src < dest)
	{
		while (n--)
			p_dest[n] = p_src[n];
	}
	else
	{
		while (n--)
		{
			p_dest[i] = p_src[i];
			i++;
		}
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*sdup;
	size_t	n;

	n = 0;
	sdup = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (sdup == NULL)
		return (NULL);
	while (s[n] != '\0')
	{
		sdup[n] = s[n];
		n++;
	}
	sdup[n] = '\0';
	return (sdup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
		if (str == NULL)
			return (NULL);
		ft_memmove(str, s1, ft_strlen(s1) + 1);
		ft_memmove((str + ft_strlen(s1)), s2, ft_strlen(s2) + 1);
		return (str);
	}
	return (0);
}
