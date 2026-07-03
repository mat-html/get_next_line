/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <jomatic@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 18:16:09 by jomatic           #+#    #+#             */
/*   Updated: 2026/07/03 18:39:35 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{

}

int main()
{
	char buffer[BUFFER_SIZE];
	int fd;

	fd = open("test_getnextline.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	read(fd, buffer, sizeof(buffer) - 1);
	printf("%s\n", buffer);
	return (0);
}
