/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 06:04:57 by vbaron            #+#    #+#             */
/*   Updated: 2016/11/06 16:37:10 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

char				*first_call(char *str, int fd)
{
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				read_ret;

	str = ft_strnew(1);
	while ((read_ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[read_ret] = '\0';
		tmp = str;
		if (!(str = ft_strjoin(str, buff)))
			return (NULL);
		ft_strdel(&tmp);
	}
	if (read_ret == -1)
		return (NULL);
	return (str);
}

int					get_next_line(int const fd, char **line)
{
	static char		*str[MAXFILE];
	int				i;

	i = 0;
	if (fd < 0 || fd > MAXFILE || line == NULL || BUFF_SIZE < 0
	|| BUFF_SIZE > BUFF_MAX)
		return (-1);
	if (str[fd] == NULL)
	{
		if ((str[fd] = first_call(str[fd], fd)) == NULL)
			return (-1);
	}
	if (str[fd][0] == '\0')
		return (0);
	while (str[fd][i] != '\0' && str[fd][i] != '\n')
		i++;
	*line = ft_strsub(str[fd], 0, i);
	if ((str[fd] = ft_strchr(str[fd], '\n')) == NULL)
		return (1);
	if (str[fd][0] != '\0')
		str[fd] = ft_strsub(str[fd], 1, ft_strlen(str[fd]));
	return (1);
}

int					main(int argc, char **argv)
{
	int				fd;
	int				fd2;
	int				fd3;
	int				i;
	int				c;
	char			**line;

	i = 1;
	c = 0;
	if (argc < 2)
	{
		ft_putstr("il manque pas qqu chose ?");
		return (0);
	}
	line = (char **)malloc(sizeof(char*));
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	fd3 = open(argv[3], O_RDONLY);
	ft_putstr("\nTest1:\n");
	while (i > 0 && c != 2)
	{
		i = get_next_line(fd, line);
		if (i > 0 && *line[0] != '\0')
			ft_putstr(*line);
		if (i == -1)
			write(1, "\nerror\n", 7);
		else if (i == 0)
			write(1, "\nEOF\n", 5);
		else
			write(1, "\nLigneLue\n", 10);
		c++;
	}
	i = 1;
	ft_putstr("\nTest2:\n");
	while (i > 0 && c != 0)
	{
		i = get_next_line(fd2, line);
		if (i > 0 && *line[0] != '\0')
			ft_putstr(*line);
		if (i == -1)
			write(1, "\nerror\n", 7);
		else if (i == 0)
			write(1, "\nEOF\n", 5);
		else
			write(1, "\nLigneLue\n", 10);
		c--;
	}
	i = 1;
	ft_putstr("\nTest1:\n");
	while (i > 0)
	{
		i = get_next_line(fd, line);
		if (i > 0 && *line[0] != '\0')
			ft_putstr(*line);
		if (i == -1)
			write(1, "\nerror\n", 7);
		else if (i == 0)
			write(1, "\nEOF\n", 5);
		else
			write(1, "\nLigneLue\n", 10);
		c++;
	}
	i = 1;
	ft_putstr("\nTest2:\n");
	while (i > 0)
	{
		i = get_next_line(fd2, line);
		if (i > 0 && *line[0] != '\0')
			ft_putstr(*line);
		if (i == -1)
			write(1, "\nerror\n", 7);
		else if (i == 0)
			write(1, "\nEOF\n", 5);
		else
			write(1, "\nLigneLue\n", 10);
		c++;
	}
	i = 1;
	ft_putstr("\nTest3:\n");
	while (i > 0)
	{
		i = get_next_line(fd3, line);
		if (i > 0 && *line[0] != '\0')
			ft_putstr(*line);
		if (i == -1)
			write(1, "\nerror\n", 7);
		else if (i == 0)
			write(1, "\nEOF\n", 5);
		else
			write(1, "\nLigneLue\n", 10);
	}
	close(fd3);
	close(fd2);
	close(fd);
	return (0);
}
