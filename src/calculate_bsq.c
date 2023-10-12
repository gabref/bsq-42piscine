/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_bsq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:14:06 by galves-f          #+#    #+#             */
/*   Updated: 2023/10/12 12:20:56 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

void	process_empty(t_map_data *d, unsigned int x, unsigned int y)
{

}

t_bool	process_and_check(t_map_data *d, unsigned int *x, unsigned int *y)
{
	return (TRUE);
}

t_bool	calculate_bsq(t_map_data *d)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	i;

	i = d->map_beg;
	x = 0;
	y = 0;
	while (i < (d->columns + 1) * d->lines)
	{
		if (y >= d->lines)
			return (ft_print_error("map error\n"));
		else if (d->o_map[i] == d->empty)
			process_empty(d, x, y);
		else if (d->o_map[i] == d->obstacle)
			d->matrix[y][x] = 0;
		else if (!process_and_check(d, &x, &y, i))
			return (FALSE);
		i++;
		x++;
	}
	return (TRUE);
}
