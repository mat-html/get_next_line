/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <jomatic@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 18:17:01 by jomatic           #+#    #+#             */
/*   Updated: 2026/07/18 09:42:41 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
void    *ft_calloc(size_t n, size_t size);
char    *ft_strjoin(char const *s1, char const *s2);
char *find_new_line(char *stash);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);

#endif
