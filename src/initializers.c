/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:41:41 by galves-f          #+#    #+#             */
/*   Updated: 2023/10/12 11:41:55 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

void	init_map(t_map_data *d)
{
	d->lines = 0;
	d->columns = 0;
	d->x = 0;
	d->y = 0;
	d->o_map = NULL;
	d->matrix = NULL;
}

int	init_matrix(t_map_data *d)
{
	unsigned int	i;

	d->matrix = (short **) malloc(sizeof(short **) * d->lines);
	if (!d->matrix)
		return (ft_print_error("Error: Malloc failed\n"));
	i = 0;
	while (i < d->lines)
	{
		d->matrix[i] = (short *) malloc(sizeof(short *) * d->columns);
		if (!d->matrix[i])
			return (ft_print_error("Error: Malloc failed\n"));
		i++;
	}
	return (1);
}
