#include "get_next_line.h"
#include <fcntl.h>

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
	fd = 0;
	line = (char **)malloc(sizeof(char*));
	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	fd3 = open(argv[3], O_RDONLY);
	ft_putstr("Test1:\n");
	while (i > 0 && c != 2)
	{
		i = get_next_line(fd, line);
		if (i > 0 && *line[0] != '\0')
			ft_putstr(*line);
		if (i == -1)
			ft_putstr("/			/error\n");
		else if (i == 0)
			ft_putstr("/				/EOF\n");
		else
			ft_putstr("/			/LigneLue\n");
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
			ft_putstr("/			/error\n");
		else if (i == 0)
			ft_putstr("/				/EOF\n");
		else
			ft_putstr("/			/LigneLue\n");
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
			ft_putstr("/			/error\n");
		else if (i == 0)
			ft_putstr("/				/EOF\n");
		else
			ft_putstr("/			/LigneLue\n");
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
			ft_putstr("/			/error\n");
		else if (i == 0)
			ft_putstr("/				/EOF\n");
		else
			ft_putstr("/			/LigneLue\n");
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
			ft_putstr("/			/error\n");
		else if (i == 0)
			ft_putstr("/				/EOF\n");
		else
			ft_putstr("/			/LigneLue\n");
}
	close(fd3);
	close(fd2);
	close(fd);
	return (0);
}
