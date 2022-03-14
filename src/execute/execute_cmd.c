/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:31:54 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/07 01:54:56 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

void	ft_execute_cmd(t_shell *shell, t_token *token, t_envs_lst *env)
{
	if (ft_is_builtin(token))
		ft_execute_builtins(shell, token, env);
	else
		ft_execute_bins(shell, token, env);
}
