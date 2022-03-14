/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:34:12 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/12 23:34:44 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

static void	initialize_shell(t_shell *shell)
{
	shell->pid = 0;
	shell->f_in = -1;
	shell->f_out = -1;
	shell->process_level = DEFAULT;
}

static void	run_shell(t_shell *shell, t_envs_lst *envs)
{
	char		*username;
	char		*prompt;
	char		*buf;

	username = ft_search_env_var(&envs, "USER");
	if (username)
		prompt = ft_strjoin(username, "$ ");
	else
		prompt = ft_strjoin("", "$ ");
	if (prompt == NULL)
	{
		printf("\033[A%sexit\n", prompt);
		ft_malloc_error();
	}
	buf = readline(prompt);
	if (buf == NULL)
	{
		printf("\033[A%sexit\n", prompt);
		exit(ER_MAL);
	}
	add_history(buf);
	ft_parse(shell, envs, buf, prompt);
	free(buf);
	free(prompt);
}

static void	start_shell(t_envs_lst *envs, t_shell *shell)
{
	shell->is_running = true;
	shell->exit_status = ER_NON;
	while (shell->is_running)
	{
		ft_tty_mask();
		ft_start_signals();
		initialize_shell(shell);
		run_shell(shell, envs);
		ft_start_signals();
	}
}

int	main(int argc, char **argv, char **env)
{
	t_envs_lst	*envs;
	t_shell		shell;

	(void) argc;
	(void) argv;
	envs = NULL;
	ft_parse_envs_to_lst(&envs, env);
	if (ft_search_env_var(&envs, "SHLVL"))
		shell.shlvl = ft_atoi(ft_search_env_var(&envs, "SHLVL"));
	else
		shell.shlvl = SHLVL_DEFAULT;
	shell.tmpfile = ft_strjoin(TMP_PATH, TMP_FILE);
	if (shell.tmpfile == NULL)
		ft_malloc_error();
	shell.std_in = dup(0);
	shell.std_out = dup(1);
	if (shell.std_in == -1 || shell.std_out == -1)
		exit(ER_DUP);
	start_shell(envs, &shell);
	if (close(shell.std_in) == -1 || close (shell.std_out) == -1)
		ft_close_error();
	return (shell.exit_status);
}
