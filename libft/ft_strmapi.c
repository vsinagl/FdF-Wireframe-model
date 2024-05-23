/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:00:36 by vsinagl           #+#    #+#             */
/*   Updated: 2023/10/24 18:04:23 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newchar;
	unsigned int	i;

	if (f == NULL || s == NULL)
		return (NULL);
	newchar = ft_strdup(s);
	if (newchar == NULL)
		return (NULL);
	i = 0;
	while (newchar[i] != '\0')
	{
		newchar[i] = f(i, newchar[i]);
		i++;
	}
	return (newchar);
}
