/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:15:39 by crendeha          #+#    #+#             */
/*   Updated: 2021/10/06 20:07:00 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		needle_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *) haystack);
	i = 0;
	while (haystack[i] != '\0' && (int)(len - i) >= needle_len)
	{
		if (haystack[i] == needle[0])
		{
			if (ft_strncmp(&haystack[i], &needle[0], needle_len) == 0)
				return ((char *) &haystack[i]);
		}
		i++;
	}
	return (NULL);
}
