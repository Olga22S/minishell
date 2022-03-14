/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:22:45 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/10 20:40:37 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/main.h"

void	ft_unset(t_shell *shell, t_envs_lst **envs, t_token *token)
{
	while (token && token->type == ARG)
	{
		if (!ft_check_env_syntax(token->str))
		{
			shell->exit_status = ER_MAIN;
			ft_putstr_fd(ft_search_env_var(envs, "USER"), STDERR_FILENO);
			ft_putstr_fd(": unset: `", STDERR_FILENO);
			ft_putstr_fd(token->str, STDERR_FILENO);
			ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
		}
		else
		{
			ft_remove_env_var(envs, token->str);
			shell->exit_status = ER_NON;
		}
		token = token->next;
	}
	shell->exit_status = ER_NON;
}
