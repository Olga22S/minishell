/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:26:11 by crendeha          #+#    #+#             */
/*   Updated: 2021/10/05 17:13:23 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_memory(char **new_strings, int i)
{
	while (i >= 0)
		free(new_strings[i--]);
	free(new_strings);
}

static int	get_num_of_words(char const *s, char c)
{
	char	*ptr;
	int		words;

	ptr = (char *)s;
	words = 0;
	while (*ptr != '\0')
	{
		while (*ptr != '\0' && *ptr == c)
			ptr++;
		if (*ptr != '\0')
			words++;
		while (*ptr != '\0' && *ptr != c)
			ptr++;
	}
	return (words);
}

static int	get_word_size(char const *ptr, char c)
{
	int		word_size;

	word_size = 0;
	while (*ptr != '\0' && *ptr != c)
	{
		word_size++;
		ptr++;
	}
	return (word_size);
}

static	char	*write_word(char **new_strings, int i, char *ptr, char c)
{
	int	j;

	new_strings[i] = malloc(get_word_size(ptr, c) + 1);
	if (new_strings[i] == NULL)
	{
		free_memory(new_strings, i - 1);
		return (NULL);
	}
	j = 0;
	while (*ptr != '\0' && *ptr != c)
		new_strings[i][j++] = *ptr++;
	new_strings[i][j] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**new_strings;
	char	*ptr;
	int		i;

	if (s == NULL)
		return (NULL);
	new_strings = malloc((get_num_of_words(s, c) + 1) * sizeof(char *));
	if (new_strings == NULL)
		return (NULL);
	i = 0;
	ptr = (char *)s;
	while (*ptr != '\0')
	{
		while (*ptr != '\0' && *ptr == c)
			ptr++;
		if (*ptr != '\0')
		{
			ptr = write_word(new_strings, i++, ptr, c);
			if (ptr == NULL)
				return (NULL);
		}
	}
	new_strings[i] = NULL;
	return (new_strings);
}
