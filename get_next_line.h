/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <jomatic@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 18:17:01 by jomatic           #+#    #+#             */
/*   Updated: 2026/07/03 18:41:48 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>


#define BUFFER_SIZE 4

char	*get_next_line(int fd);

#endif
