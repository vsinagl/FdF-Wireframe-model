/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:40:52 by vsinagl           #+#    #+#             */
/*   Updated: 2023/10/24 17:42:07 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p_m, int byte, size_t n)
{
	size_t			i;
	unsigned char	*p_char;

	p_char = (unsigned char *)p_m;
	i = 0;
	while (i < n)
	{
		*p_char = (unsigned char)byte;
		p_char++;
		i++;
	}
	return (p_m);
}
