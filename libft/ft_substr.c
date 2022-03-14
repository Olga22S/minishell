/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:52:08 by crendeha          #+#    #+#             */
/*   Updated: 2021/11/16 17:44:31 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	i;

	if (s == NULL || (unsigned int)ft_strlen(s) <= start)
		len = 0;
	new_s = malloc((len + 1) * sizeof(char));
	if (new_s == NULL)
		return (new_s);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		new_s[i] = s[start + i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
