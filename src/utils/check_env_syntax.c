/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env_syntax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:40:04 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/10 20:37:43 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static bool	starts_with_correct_char(char *key)
{
	if (key && (ft_isalpha(key[0]) || key[0] == '_'))
		return (true);
	else
		return (false);
}

static bool	valid_chars(char *key)
{
	int	i;

	i = 0;
	while (key[i] != '\0' && key[i] != '=')
	{
		if (ft_isalnum(key[i]) || key[i] == '_')
			i++;
		else
			return (false);
	}
	return (true);
}

bool	ft_check_env_syntax(char *key)
{
	if (!starts_with_correct_char(key) || !valid_chars(key))
		return (false);
	else
		return (true);
}
