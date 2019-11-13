/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:13:27 by ahallain          #+#    #+#             */
/*   Updated: 2019/11/13 16:47:24 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*memory;
	char		*buffer;
	int			ret;
	int			read_value;
	int			size;

	size = BUFFER_SIZE < 100000 ? BUFFER_SIZE : 128;
	if ((!memory && !(memory = malloc(1))
		&& (*memory = 0))
		|| !(buffer = malloc(size + 1)))
		return (-1);
	while (!ft_strcchr(memory, '\n')
		&& (read_value = read(fd, buffer, size)) > 0)
	{
		buffer[read_value] = 0;
		ft_stradd(&memory, buffer);
	}
	*line = ft_firstchr(memory, '\n');
	ret = ft_strcchr(memory, '\n');
	ft_chrmove(&memory, '\n');
	free(buffer);
	if (read_value == -1)
		return (-1);
	return (ret);
}