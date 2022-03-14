/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:10:27 by crendeha          #+#    #+#             */
/*   Updated: 2021/10/05 15:49:03 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	size;
	char	*ptr_new_s;
	char	*ptr_old_s;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_s = malloc(size);
	if (new_s == NULL)
		return (NULL);
	ptr_new_s = new_s;
	ptr_old_s = (char *)s1;
	while (*ptr_old_s != '\0')
		*ptr_new_s++ = *ptr_old_s++;
	ptr_old_s = (char *)s2;
	while (*ptr_old_s != '\0')
		*ptr_new_s++ = *ptr_old_s++;
	*ptr_new_s = '\0';
	return (new_s);
}
