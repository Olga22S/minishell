/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 02:16:10 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/10 17:18:43 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/main.h"

void	ft_handle_invalid_path(t_shell *shell, t_envs_lst **envs,
	char *path_to_go)
{
	shell->exit_status = ER_MAIN;
	ft_putstr_fd(ft_search_env_var(envs, "USER"), STDERR_FILENO);
	ft_putstr_fd(": cd: ", STDERR_FILENO);
	ft_putstr_fd(path_to_go, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
}

bool	ft_handle_empty_path(t_shell *shell, t_envs_lst **envs)
{
	char	*home_path;

	home_path = ft_search_env_var(envs, "HOME");
	if (home_path == NULL)
	{
		shell->exit_status = ER_MAIN;
		ft_putstr_fd(home_path, STDERR_FILENO);
		ft_putstr_fd(": cd: HOME not set", STDERR_FILENO);
		return (false);
	}
	else
	{
		if (chdir(home_path) == -1)
		{
			ft_handle_invalid_path(shell, envs, home_path);
			return (false);
		}
		return (true);
	}
}
