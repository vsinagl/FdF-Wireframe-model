/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:06:03 by vsinagl           #+#    #+#             */
/*   Updated: 2023/10/24 18:06:05 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			src_len;
	size_t			dst_len;
	size_t			i;
	unsigned char	*s;

	src_len = ft_strlen((char *)src);
	dst_len = ft_strlen((char *)dst);
	s = (unsigned char *)src;
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (s[i] != '\0' && (i + dst_len + 1 < size))
	{
		dst[dst_len + i] = s[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}
