/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:45:27 by vsinagl           #+#    #+#             */
/*   Updated: 2023/11/02 14:15:36 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_substr_dup(char *sub, char *s_mod,
				size_t mallen, unsigned int start)
{
	size_t	i;

	i = 0;
	while (i + 1 < mallen)
	{
		sub[i] = s_mod[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	char			*s_mod;
	size_t			mallen;

	s_mod = (char *)s;
	if (!s_mod)
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
		return (ft_strdup(""));
	if ((ft_strlen(s_mod) - start) <= len)
		mallen = (ft_strlen(s_mod) - start + 1) * sizeof(char);
	else
		mallen = (len + 1) * sizeof(char);
	sub = (char *)malloc(mallen);
	if (sub == NULL)
		return (NULL);
	sub = ft_substr_dup(sub, s_mod, mallen, start);
	return (sub);
}
