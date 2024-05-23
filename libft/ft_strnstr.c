/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:04:34 by vsinagl           #+#    #+#             */
/*   Updated: 2023/10/24 18:04:36 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *find, size_t n)
{
	char		*s;
	char		*f;
	size_t		i;

	s = (char *)src;
	f = (char *)find;
	i = 0;
	if (*f == '\0')
		return (s);
	while (*s != '\0' && n > 0)
	{
		while (s[i] == f[i] && f[i] != '\0' && i < n)
			i++;
		if (f[i] == '\0')
			return (s);
		i = 0;
		s++;
		n--;
	}
	return (NULL);
}
