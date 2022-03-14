/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:22:30 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/13 00:14:48 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

bool	ft_prev_redirect(t_token *token)
{
	while (token && token->type != CMD)
	{
		if (token->type == TRUNC || token->type == APPEND)
			return (true);
		token = token->prev;
	}
	return (false);
}

void	ft_handle_redirections(t_shell *shell, t_token *token)
{
	char	*ts;

	ts = ft_strtrim(token->str, " ");
	if (ts == NULL)
		ft_malloc_error();
	if (!errno && shell->f_out != -1 && close(shell->f_out) == -1)
		ft_close_error();
	if (token->prev->type == TRUNC)
		shell->f_out = open(ts, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	else
		shell->f_out = open(ts, O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (shell->f_out == -1)
		ft_open_error();
	if (!errno && dup2(shell->f_out, STDOUT_FILENO) == -1)
		ft_dup_error();
	if (!errno && close(shell->f_out) == -1)
		ft_close_error();
	else
		shell->f_out = -1;
	free(ts);
}

void	ft_handle_input(t_shell *shell, t_token *token, t_envs_lst *env)
{
	char	*ts;

	ts = ft_strtrim(token->str, " ");
	if (ts == NULL)
		ft_malloc_error();
	if (!errno && shell->f_in != -1 && close(shell->f_in) == -1)
		return ;
	shell->f_in = open(ts, O_RDONLY, 0777);
	if (shell->f_in == -1)
		ft_print_errno_error(shell, ts, &env);
	if (!errno && dup2(shell->f_in, STDIN_FILENO) == -1)
		ft_dup_error();
	if (!errno && close(shell->f_in) == -1)
		ft_close_error();
	else
		shell->f_in = -1;
	free(ts);
}

void	ft_handle_dobinp(t_shell *shell, t_token *token, t_envs_lst *env)
{
	int		fd;
	pid_t	pid;
	char	*eof;

	if (dup2(shell->std_in, STDIN_FILENO) == -1
		|| dup2(shell->std_out, STDOUT_FILENO) == -1)
		ft_dup_error();
	fd = open(shell->tmpfile, O_TRUNC | O_CREAT | O_WRONLY, 0777);
	if (fd == -1)
		ft_open_error();
	eof = ft_strjoin(token->str, "\n");
	if (eof == NULL)
		ft_malloc_error();
	signal(SIGINT, ft_sig_empty);
	pid = fork();
	if (pid == 0)
		ft_handle_child_dobinp(fd, eof);
	else if (pid > 0)
	{
		ft_handle_parent_dobinp(shell, fd, pid, env);
		free(eof);
	}
	else
		ft_fork_error();
}

int	ft_handle_pipe(t_shell *shell)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_pipe_error();
	pid = fork();
	if (pid == 0)
		return (ft_handle_child_pipe(shell, fd));
	else if (pid > 0)
		return (ft_handle_parent_pipe(shell, fd, pid));
	else
	{
		ft_fork_error();
		return (DEFAULT);
	}
}
