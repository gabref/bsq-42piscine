/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 07:58:31 by galves-f          #+#    #+#             */
/*   Updated: 2023/10/12 11:57:20 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"
#include <stdio.h>

int		bsq(t_map_data *d, char *file);

int	main(int ac, char **av)
{
	t_map_data	d;
	int			i;

	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			if (bsq(&d, av[i]))
			{
				ft_putstr(1, d.o_map);
				ft_putstr(1, "\n");
			}
			i++;
		}
	}
	else
		return (bsq(&d, NULL));
	return (0);
}

int	bsq(t_map_data *d, char *file)
{
	int	ok;
	init_map(d);
	if (!file)
	{
		if (!read_stdin(d))
			return (clean_up(d, FALSE));
	}
	else
	{
		if (!read_file(d, file))
			return (clean_up(d, FALSE));
	}
	if (!validate_map(d))
		return (FALSE);
	ok = init_matrix(d);
	if (!ok)
		return (clean_up(d, FALSE));
	return (1);
}
