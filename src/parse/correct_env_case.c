/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_env_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:24:54 by gkelsie           #+#    #+#             */
/*   Updated: 2021/12/12 21:13:40 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static char	*str_lower(char *str)
{
	char	*new_str;
	int		i;

	new_str = (char *)malloc(sizeof(char) * 4);
	if (new_str == NULL)
		ft_malloc_error();
	new_str[3] = '\0';
	i = 0;
	while (*str)
	{
		if (ft_isalpha(*str))
			new_str[i] = ft_tolower(*str);
		else
			new_str[i] = *str;
		i++;
		str++;
	}
	return (new_str);
}

static bool	check_env_registr(char *str)
{
	char	*new_str;

	if (str == NULL || ft_strlen(str) != 3)
		return (false);
	new_str = str_lower(str);
	if (new_str == NULL)
		return (false);
	if (ft_strncmp(new_str, "env", 3) != 0)
	{
		free(new_str);
		return (false);
	}
	free(new_str);
	return (true);
}

static bool	check_env_around(char *left, char *right)
{
	if (left)
	{
		while (*left)
		{
			if (ft_strchr_bo("<>|;", *left))
			{
				left++;
				continue ;
			}
			return (false);
		}
	}
	if (right)
	{
		while (*right)
		{
			if (ft_strchr_bo("<>|;", *right))
			{
				right++;
				continue ;
			}
			return (false);
		}
	}
	return (true);
}

void	ft_low_up_token(char **coms)
{
	int	i;

	i = -1;
	while (coms[++i])
	{
		if ((i == 0 && check_env_registr(coms[i]))
			|| (coms[i + 1] == NULL
				&& check_env_registr(coms[i])
				&& check_env_around(coms[i - 1], NULL))
			|| (i != 0 && coms[i + 1] != NULL
				&& check_env_registr(coms[i])
				&& check_env_around(coms[i - 1], coms[i + 1])))
		{
			free(coms[i]);
			coms[i] = NULL;
			coms[i] = ft_strdup("env");
			if (coms[i] == NULL)
				ft_malloc_error();
		}
	}
}
