#include "../includes/fdf.h"

int	get_matrix_width(char *line)
{
	int	count;

	count = 0;
	while(1)
	{
		while(*line == ' ' || *line == '-' || *line == '+')
			line++;
		if (ft_isdigit(*line))
			count++;
		while(ft_isdigit(*line))
			line++;
		if (*line == ',')
		{
			line++;
			while(ft_isalpha(*line) || ft_isdigit(*line))
				line++;
			while(*line == ' ')
				line++;
		}
		if (*line == '\n' || *line == '\0')
			break;
	}
	return(count);
}

int	get_color(char *line)
{
	char str_dup[11];
	int	i;

	i = 0;
	while(line[i] != ' ' && line[i] != '\n' && line[i] != '\0')
	{
		if (i > 8)
			break;
		str_dup[i] = ft_toupper(line[i]);
		i++;
	}
	str_dup[i] = '\0';
	int number = (ft_atoi_base("0123456789ABCDEF", &str_dup[2])); // << 8 | 0xFF);
	return(number);
}
