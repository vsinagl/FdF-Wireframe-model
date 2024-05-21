#include "../../includes/libft.h"

int	ft_isdigit(char str)
{
	if (str < '0' || str > '9')
		return (0);
	return (1);
}
