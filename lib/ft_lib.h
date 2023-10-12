/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:00:43 by galves-f          #+#    #+#             */
/*   Updated: 2023/10/12 09:41:51 by galves-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str);
void 	ft_putstr(int fd, char *str);
int 	ft_strcpy(char *dest, char *src, int size);
char 	*ft_strjoin(char *s1, int size1, char *s2, int size2);
void	*ft_realloc(void *ptr, int new_size);
void	*ft_memcpy(void *dst, void *src, int n);

#endif
