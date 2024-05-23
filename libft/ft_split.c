/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:51:56 by vsinagl           #+#    #+#             */
/*   Updated: 2023/11/02 11:37:18 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_split_splitlen(char const *s, char c)
{
	size_t		i;
	size_t		n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			n++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (n);
}

static	char	*ft_split_dup(char const *s, char c)
{
	char	*split;
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	while ((s[i] != c) && s[i] != '\0')
	{
		len++;
		i++;
	}
	split = (char *)malloc(sizeof(char) * (len + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		split[i] = s[i];
		i++;
	}
	split[i] = '\0';
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char		**arr;
	size_t		i;
	size_t		n;

	i = 0;
	n = 0;
	n = ft_split_splitlen(s, c);
	arr = (char **)malloc(sizeof(char *) * (n + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		while (*s == c)
			s++;
		arr[i] = ft_split_dup(s, c);
		s += (ft_strlen(arr[i]) + 1);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

// int main(void)
// {
// 	char *str = "oneword";
// 	printf("len is: %li\n", ft_split_splitlen(str,' '));
// }