/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:44:00 by galves-f          #+#    #+#             */
/*   Updated: 2023/10/12 09:46:17 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lib.h"

char	*ft_strjoin(char *s1, int size1, char *s2, int size2)
{
	char	*res;

	res = (char *) malloc(sizeof(char) * (size1 + size2 + 1));
	if (!res)
		return (NULL);
	ft_strcpy(res, s1, size1);
	ft_strcpy(&res[size1], s2, size2);
	free(s1);
	return (res);
}
