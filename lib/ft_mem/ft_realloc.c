/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:38:16 by galves-f          #+#    #+#             */
/*   Updated: 2023/10/12 08:41:08 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lib.h"

void	*ft_realloc(void *ptr, int new_size)
{
	char	*new_ptr;
	int		cur_size;

	if (ptr == 0)
		return (malloc(new_size));
	cur_size = sizeof(ptr);
	if (new_size <= cur_size)
		return (ptr);
	new_ptr = malloc(new_size);
	ft_memcpy(ptr, new_ptr, cur_size);
	free(ptr);
	return (new_ptr);
}
