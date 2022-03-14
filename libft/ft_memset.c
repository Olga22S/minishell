/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:16:31 by crendeha          #+#    #+#             */
/*   Updated: 2021/10/05 02:26:10 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*c_b;
	size_t			i;

	i = 0;
	c_b = (unsigned char *) b;
	while (i < len)
	{
		c_b[i] = (unsigned char) c;
		i++;
	}
	return (b);
}
