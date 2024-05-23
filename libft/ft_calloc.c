/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:47:32 by vsinagl           #+#    #+#             */
/*   Updated: 2023/11/02 12:07:02 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*p;

	if (nitems && (size_t)(-1) / nitems < size)
		return (NULL);
	p = (void *)malloc(size * nitems);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, size * nitems);
	return (p);
}
//first if: checking for size_t value overflow.
//second if: checking if i malloc sucesfully
//
//using memset to be sure that there will be 
//nulls in memory block allocated by calloc