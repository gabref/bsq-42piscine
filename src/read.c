/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:39:23 by galves-f          #+#    #+#             */
/*   Updated: 2023/10/12 11:40:34 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

t_bool	read_stdin(t_map_data *d)
{
	if (!read_map(d, 0, BUFFER_STDIN))
		return (FALSE);
	// TODO validations
	return (TRUE);
}

t_bool	read_file(t_map_data *d, char *file)
{
	d->o_map = NULL;
	d->fd = open(file, O_RDONLY);
	if (d->fd < 0)
		return (ft_print_error("Error: Open file failed\n"));
	if (!read_map(d, d->fd, BUFFER_READ ))
	{
		close(d->fd);
		return (FALSE);
	}
	close(d->fd);
	// TODO validations
	return (TRUE);
}

t_bool	read_map(t_map_data *d, int fd, int buffer_size)
{
	char			*buffer;
	int				bytes_read;
	int				map_size;

	buffer = (char *) malloc(sizeof(char) * buffer_size + 1);
	if (!buffer)
		return (ft_print_error("Error: Malloc failed\n"));
	bytes_read = read(fd, buffer, buffer_size);
	buffer[bytes_read] = '\0';
	map_size = 0;
	while (bytes_read != 0)
	{
		d->o_map = ft_strjoin(d->o_map, map_size, buffer, buffer_size);
		if (!d->o_map)
			return (ft_print_error("Error: Malloc failed\n"));
		map_size += bytes_read;
		bytes_read = read(fd, buffer, buffer_size);
		if (bytes_read < 0)
			return (ft_print_error("Reading of file failed\n"));
		buffer[bytes_read] = '\0';
	}
	free(buffer);
	return (TRUE);
}
