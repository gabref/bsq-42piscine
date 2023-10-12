/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:42:23 by galves-f          #+#    #+#             */
/*   Updated: 2023/10/12 12:20:53 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

/*
   gets characters of map and
   checks for maps erros:
   1 - file need more than one line
   2 - map char cant be the same
   3 - lines isnt a number
   */
t_bool	map_chars(t_map_data *d)
{
	unsigned int	x;
	unsigned int	i;

	i = 0;
	while (d->o_map[i] && d->o_map[i] != '\n')
		i++;
	if (!d->o_map[i] || !d->o_map[i + 1])
		return (ft_print_error("map error\n"));
	d->map_beg = i + 1;
	d->full = d->o_map[--i];
	d->obstacle = d->o_map[--i];
	d->empty = d->o_map[--i];
	if (d->full == d->obstacle || d->full == d->empty 
		|| d->empty == d->obstacle)
		return (ft_print_error("map error\n"));
	x = 0;
	d->lines = 0;
	while (x < i)
	{
		if (d->o_map[x] > '9' || d->o_map[x] < '0')
			return (ft_print_error("map error\n"));
		d->lines = d->lines * 10 + d->o_map[x++] - '0';
	}
	return (TRUE);
}

/*
   get columns of map and
   checks for maps erros:
   1 - lines cant be equal to 0
   2 - columns cant be equal to 0
   3 - all columns must be equals
   */
t_bool	get_columns(t_map_data *d)
{
	unsigned int	i;

	if (d->lines == 0)
		return (ft_print_error("map error\n"));
	i = d->map_beg;
	while (d->o_map[i] && d->o_map[i] != '\n')
		i++;
	d->columns = i - d->map_beg;
	if (d->columns == 0)
		return (ft_print_error("map error\n"));
	return (TRUE);
}

t_bool	validate_map(t_map_data *d)
{
	if (!map_chars(d) || !get_columns(d))
		return (FALSE);
	return (TRUE);
}
