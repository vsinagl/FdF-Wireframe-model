/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:05:33 by vsinagl           #+#    #+#             */
/*   Updated: 2023/10/24 18:05:35 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	findcmp(char *s1, char *find)
{
	int	i;

	i = 0;
	while (find[i] != '\0')
	{
		if (s1[i] != find[i])
			return (s1[i] - find[i]);
		i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *find)
{
	while (*str != '\0')
	{
		if (*str == *find)
			if (findcmp(str, find) == 0)
				return (str);
		str++;
	}
	return (NULL);
}
// int	main(void)
// {
// 	char *str = "ahoja jak se mas";
// 	char *find = "mas";
// 	printf("result is: %s\n", ft_strstr(str,find));
// 	return (0);
// }
