/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:05:29 by vsinagl           #+#    #+#             */
/*   Updated: 2023/12/05 23:02:49 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*splitline(char **line, char *cursor)
{
	size_t		len;
	char		*tmp;

	tmp = cursor;
	len = ft_strchr_m(cursor, '\n');
	*line = ft_substr(cursor, 0, len);
	cursor = ft_substr(cursor, len, ft_strlen(cursor) + 1);
	if (tmp != NULL)
		free(tmp);
	return (cursor);
}

char	*read_line(int fd, char *buff, char *cursor)
{
	int		read_err;
	char	*tmp;

	while (1)
	{
		read_err = read(fd, buff, BUFFER_SIZE);
		if (read_err < 0)
		{
			free(cursor);
			return (NULL);
		}
		if (cursor == NULL || !cursor)
			cursor = ft_strdup("");
		if (read_err == 0)
			break ;
		buff[read_err] = '\0';
		tmp = cursor;
		cursor = ft_strjoin(cursor, buff);
		if (tmp != NULL)
			free(tmp);
		if (ft_strchr_m(cursor, '\n'))
			break ;
	}
	return (cursor);
}

char	*free_cursor(char **cursor)
{
	if (cursor && *cursor)
	{
		free(*cursor);
		*cursor = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*cursor[1024];
	char		*line;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	cursor[fd] = read_line(fd, buff, cursor[fd]);
	free(buff);
	if (cursor[fd] == NULL)
		return (NULL);
	if (*cursor[fd] == '\0')
		return (free_cursor(&cursor[fd]));
	if (!ft_strchr_m(cursor[fd], '\n'))
	{
		line = ft_strdup(cursor[fd]);
		free(cursor[fd]);
		cursor[fd] = NULL;
		return (line);
	}
	cursor[fd] = splitline(&line, cursor[fd]);
	return (line);
}
