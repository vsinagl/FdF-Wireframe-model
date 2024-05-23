/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:40:41 by vsinagl           #+#    #+#             */
/*   Updated: 2023/11/03 19:31:23 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*lst_i;
	int		i;

	lst_i = lst;
	i = 0;
	while (lst_i != NULL)
	{
		lst_i = lst_i->next;
		i++;
	}
	return (i);
}
