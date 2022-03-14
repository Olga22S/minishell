/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:50:04 by crendeha          #+#    #+#             */
/*   Updated: 2021/10/05 16:24:36 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	char	*ptr;

	ptr = (char *)set;
	while (*ptr != '\0')
	{
		if (*ptr == c)
			return (1);
		ptr++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*new_str;
	int		i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && is_in_set(s1[start], set))
		start++;
	end = (int) ft_strlen(s1) - 1;
	while (end >= 0 && is_in_set(s1[end], set))
		end--;
	if (start >= end)
		new_str = malloc(1);
	else
		new_str = malloc((size_t)(end - start + 2));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
		new_str[i++] = s1[start++];
	new_str[i] = '\0';
	return (new_str);
}
