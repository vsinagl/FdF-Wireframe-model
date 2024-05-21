/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:05:29 by vsinagl           #+#    #+#             */
/*   Updated: 2023/12/04 16:25:22 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *str);
size_t	ft_strchr_m(const char *s, int c);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *p_m, int byte, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*read_newline(int fd, char *buff, char **cursor, char *buff_read);
char	*newline_join(char *buff, char *buff_read, char **cursor);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
