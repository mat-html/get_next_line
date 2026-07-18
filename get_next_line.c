/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <jomatic@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 18:16:09 by jomatic           #+#    #+#             */
/*   Updated: 2026/07/18 11:58:48 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_file(int fd, char *stash)
{
	char *buff;
	int readed;
	char *temp;
	
	readed = 1;
	while (!find_new_line(stash) && readed != 0)
	{
		buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		readed = (int)read(fd, buff, BUFFER_SIZE);
		if (readed == -1 || (!stash && readed == 0))
			return (free(stash), free(buff), NULL);
		buff[readed] = '\0';
		stash = ft_strjoin(stash, buff);
		free (buff);
	}
	return (stash);	
}

char	*ft_get_line(char *stash)
{
	size_t	i;
	char	*line;

	i =	0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{	
		line[i] = stash[i];
		i++;
	}
	line[i++] = '\n';
	line[i] = '\0';
	return (line);	
}

char	*ft_get_rest(char *line, char *stash)
{
	size_t i;
	size_t j;
	char *rest;

	i = ft_strlen(line);
	j = 0;
	if (!stash[i])
		return (free(stash), NULL);
	while (stash[i++])
		j++;
	rest = ft_calloc((j + 1), sizeof(char));
	i = ft_strlen(line);
	j = 0;
	while (stash[i] != '\0')
	{
		rest[j] = stash[i];
		j++;
		i++;
	}
	rest[i] = '\0';
	return(free(stash), rest);
}

char	*get_next_line(int fd)
{
	static char *buffer;
	char		*line;
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
	line = ft_get_line(buffer);
	buffer = ft_get_rest(line, buffer);
	return (line);
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
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}
