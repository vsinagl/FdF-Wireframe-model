/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:00:28 by vsinagl           #+#    #+#             */
/*   Updated: 2023/11/02 19:21:00 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set_char(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trm;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (is_set_char(s1[start], set) == 0)
		start++;
	if (start == end)
	{
		return (ft_strdup(""));
	}
	while (is_set_char(s1[end - 1], set) == 0)
		end--;
	trm = ft_substr(s1, start, end - start);
	return (trm);
}

// int main(void){
// 	char *str = "xxxxxneconecosxxx";
// 	char *set = "xisdf";
// 	char *s1dup = ft_strtrim(str ,set);
// 	printf("the trimnecomed string is: %s\n", s1dup);
// 	char *s = ft_strtrim("   xxxtripouille", " x");
// 	/* 1 */ check(!strcmp(s, "tripouille"));
// 	//free(s1dup), free(s);
// 	return(0);
// }