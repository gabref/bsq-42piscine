/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:03:51 by galves-f          #+#    #+#             */
/*   Updated: 2023/10/12 12:20:45 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include "../lib/ft_lib.h"
# include <fcntl.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0
# define BUFFER_READ 256
# define BUFFER_STDIN	280000

typedef int	t_bool;

typedef struct s_map {
	unsigned int	x;
	unsigned int	y;
	unsigned int	lines;
	unsigned int	columns;
	unsigned int	map_beg;
	int				fd;
	char 			*o_map;
	char			empty;
	char			obstacle;
	char			full;
	short			**matrix;
} 	t_map_data;

void	init_map(t_map_data *d);
int		init_matrix(t_map_data *d);
void	free_matrix(t_map_data *d);
void	free_matrix_i(t_map_data *d, int i);
t_bool	clean_up(t_map_data *d, int ret);
t_bool	read_stdin(t_map_data *d);
t_bool	read_file(t_map_data *d, char *file);
t_bool	read_map(t_map_data *d, int fd, int buffer_size);
t_bool	ft_print_error(char *str);
t_bool	validate_map(t_map_data *d);

#endif
