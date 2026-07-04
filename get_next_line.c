/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <jomatic@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 18:16:09 by jomatic           #+#    #+#             */
/*   Updated: 2026/07/04 11:43:48 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_file(int fd, char *stash)
{
	char *buff;
	int readed;
	
	readed = 1;
	while (!find_new_line(stash) && readed != 0)
	{
		buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		readed = (int)read(fd, buff, BUFFER_SIZE);
		buff[readed] = '\0';
		stash = ft_strjoin(stash, buff);
		free(buff);
	}
	return (stash);	
}

char	*get_next_line(int fd)
{
	static char *buffer;
	//char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
			return (NULL);
	temp = read_file(fd, buffer);
	if (!temp)
	{
		if (buffer)
				free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = temp;
	return (buffer);
}

int main()
{
	//char buffer[BUFFER_SIZE];
	int fd;

	fd = open("test_getnextline.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	printf("%s\n", get_next_line(fd));
	return (0);
}
