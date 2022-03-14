/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:37:17 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/13 00:13:32 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static int	get_token_len(t_token *token)
{
	int	size;

	size = 1;
	while (token && token->type == ARG)
	{
		size++;
		token = token->next;
	}
	return (size);
}

static void	handle_bin_cmd(t_shell *shell, t_token *token, t_envs_lst *env)
{
	int		size;
	int		i;
	char	**args;

	if (token->type == CMD)
		ft_update_shlvl(shell, token, &env);
	size = get_token_len(token->next);
	args = (char **) malloc(sizeof(char *) * (size + 1));
	if (args == NULL)
		ft_malloc_error();
	i = -1;
	while (++i < size)
	{
		args[i] = ft_strtrim(token->str, " ");
		if (args[i] == NULL)
			ft_malloc_error();
		token = token->next;
	}
	args[size] = NULL;
	ft_launch_execve(env, args);
}

void	ft_execute_bins(t_shell *shell, t_token *token, t_envs_lst *env)
{
	pid_t	pid;
	int		status;

	ft_set_signals(token);
	pid = fork();
	if (pid == 0)
	{
		errno = 0;
		handle_bin_cmd(shell, token, env);
	}
	else if (pid > 0)
	{
		status = 0;
		shell->pid = pid;
		waitpid(pid, &status, 0);
		shell->exit_status = WEXITSTATUS(status);
	}
	else
		ft_fork_error();
}
