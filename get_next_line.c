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

char	*get_next_line(int fd)
{
	ssize_t	read_bytes;
	char	*line;
	char	buf[1];

	line = "";
	read_bytes = 1;
	while (read_bytes >= 1)
	{
		read_bytes = read(fd, buf, 1);
		if (read_bytes != 1)
			return (NULL);
		if (read_bytes == 1)
			line = ft_concatenate(line, buf[0]);
		if (buf[0] == '\n')
			break ;
	}
	return (line);
}

/*
int main ()
{
	int fd;
	char *line;
	char buffer[1];
	int	i;

	i = 1;
	fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        printf("Error: Cannot open file\n");
        return 1;
    }
	
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
