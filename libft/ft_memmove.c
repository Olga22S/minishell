/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:34:31 by crendeha          #+#    #+#             */
/*   Updated: 2021/10/05 17:46:41 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_data(char *c_dst, char *c_src, size_t len)
{
	size_t	i;

	if (c_dst > c_src)
	{
		i = len;
		while (i > 0)
		{
			c_dst[i - 1] = c_src[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			c_dst[i] = c_src[i];
			i++;
		}
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*c_dst;
	char	*c_src;

	if (dst == NULL && src == NULL && len > 0)
		return (NULL);
	c_dst = (char *) dst;
	c_src = (char *) src;
	copy_data(c_dst, c_src, len);
	return (dst);
}
