/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:40:51 by galves-f          #+#    #+#             */
/*   Updated: 2023/10/12 11:40:58 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

void	free_matrix(t_map_data *d)
{
	unsigned int	i;

	i = 0;
	while (i < d->lines)
		free(d->matrix[i++]);
	if (d->columns != 0)
		free(d->matrix);
}

void	free_matrix_i(t_map_data *d, int i)
{
	while (--i >= 0)
		free(d->matrix[i]);
	free(d->matrix);
}

int		clean_up(t_map_data *d, int ret)
{
	if (d->o_map)
		free(d->o_map);
	if (d->matrix)
		free_matrix(d);
	return (ret);
}
