/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemarti2 <pemarti2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:02:27 by pemarti2          #+#    #+#             */
/*   Updated: 2024/03/09 11:02:30 by pemarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
	#define BUFFER_SIZE 2000
#endif

char	*get_next_line(int fd)
{
	static size_t	i;
	static char		buffer[BUFFER_SIZE];
	ssize_t			read_bytes;
	char			*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL, read_bytes = 1;
	if (i == 0)
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		if (i == BUFFER_SIZE)
			read_bytes = read(fd, buffer, BUFFER_SIZE), i = 0;
		else 
		{
			line = ft_concatenate(line, buffer[i]);
			if (line == NULL)
				return (NULL);
			if (buffer[i] == '\n')
				{
					i++;
					break ;
				}
			i++;
		}
	}
	return (line);
}
/*
int main ()
{
	int fd;
	char *line;
	int	i;

	i = 1;
	fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        printf("Error: Cannot open file\n");
        return 1;
    }
	printf("payaso fd: %d\n", fd);
	line = get_next_line(fd);
	printf("fd: %d\n", fd);
	while (line)
	{
		printf("line number %d: %s", i, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);

	return (0);
}

*/