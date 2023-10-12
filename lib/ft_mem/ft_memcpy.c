/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:41:57 by galves-f          #+#    #+#             */
/*   Updated: 2023/10/12 08:45:21 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lib.h"

void	*ft_memcpy(void *dest, void *src, int n)
{
	unsigned char 	*dest_addr;
	unsigned char 	*src_addr;

	if (dest == src || n == 0)
		return (dest);
	dest_addr = (unsigned char*) dest;
	src_addr = (unsigned char*) src;
	while (--n)
		*dest_addr++ = *src_addr++;
	return (dest);
}
