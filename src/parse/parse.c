/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:57:55 by gkelsie           #+#    #+#             */
/*   Updated: 2021/12/12 21:08:19 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static bool	parse_exit(t_shell *shell, char *str, int number)
{
	free(str);
	if (number == ER_NON)
		;
	else if (number == ER_MAL)
		shell->exit_status = ER_MAL;
	return (false);
}

bool	ft_parse(t_shell *shell, t_envs_lst *env, char *str, char *user)
{
	char	*new_str;

	if (ft_skip_tabulation(str) == true)
		return (false);
	new_str = ft_trim_tabulation(str);
	if (new_str == NULL)
		ft_malloc_error();
	if (ft_preparse(new_str, user) == false)
		return (parse_exit(shell, new_str, ER_NON));
	if (ft_parse_handling(shell, env, new_str) == false)
		ft_malloc_error();
	free(new_str);
	return (true);
}
