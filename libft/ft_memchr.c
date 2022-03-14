/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:07:12 by crendeha          #+#    #+#             */
/*   Updated: 2021/10/05 02:26:06 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*c_src;

	c_src = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (c_src[i] == (unsigned char) c)
			return ((void *) &c_src[i]);
		i++;
	}
	return (NULL);
}
