/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:40:41 by vsinagl           #+#    #+#             */
/*   Updated: 2023/11/03 19:31:23 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list		*lst_i;

	if (lst == NULL)
		return (NULL);
	lst_i = lst;
	while (lst_i->next != NULL)
		lst_i = lst_i->next;
	return (lst_i);
}
