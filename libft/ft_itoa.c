/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:58:26 by vsinagl           #+#    #+#             */
/*   Updated: 2023/10/24 18:15:21 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_itoa_numlength(unsigned int n)
{
	size_t	len;

	len = 1;
	while (n / 10 >= 1)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static	char	*ft_itoa_adddigit(unsigned int n, char *str)
{
	unsigned int	mod;
	char			add;

	mod = n % 10;
	if (n / 10 >= 1)
	{
		n = n / 10;
		ft_itoa_adddigit(n, str);
	}
	add = '0' + mod;
	str[ft_strlen(str)] = add;
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned int	new_n;
	size_t			len;
	char			*str;

	len = 0;
	if (n < 0)
	{
		new_n = -1 * n;
		len++;
	}
	else
		new_n = n;
	len += ft_itoa_numlength(new_n);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	ft_itoa_adddigit(new_n, str);
	return (str);
}
