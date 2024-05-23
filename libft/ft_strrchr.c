/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:59:02 by vsinagl           #+#    #+#             */
/*   Updated: 2023/10/26 08:11:26 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)s;
	if (c > 125)
		return (res);
	while (res[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (res[i] == c)
			return (res + i);
		i--;
	}
	return (NULL);
}
