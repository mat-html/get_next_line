/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <jomatic@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 11:00:07 by jomatic           #+#    #+#             */
/*   Updated: 2026/07/18 09:45:09 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s != NULL && s[i])
	{
		i++;
	}
	return (i);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char *ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (n == 0 || size == 0)
	{
		n = 1;
		size = 1;
	}
	total_size = n * size;
	if (size != 0 && (total_size / size) != n)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*ptr;
	size_t	j;
	size_t len1;
	size_t len2;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ptr = ft_calloc((len1 + len2 + 1), sizeof(char));
	while (i < (len1 + len2))
	{
		while (i < (len1 + len2))
		{
			if (i < len1)
			{
				ptr[i] = *s1;
				s1++;
				i++;
				break ;
			}
			ptr[i] = s2[j];
			j++;
			i++;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}

char *find_new_line(char *stash)
{
	size_t	i;
	
	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash)
	{
		if(stash[i] == '\n')
			return (&stash[i]);
		i++;
	}
	return (NULL);
}
