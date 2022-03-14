/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:54:49 by a1111             #+#    #+#             */
/*   Updated: 2021/12/09 15:25:20 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

void	ft_tty_mask(void)
{
	struct termios	sterm;

	tcgetattr(0, &sterm);
	sterm.c_lflag &= ~ECHOCTL;
	tcsetattr(0, 0, &sterm);
}

void	ft_c_handle(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ft_c_handle_fork(int sig)
{
	(void)sig;
	write(1, "\n", 1);
}

void	ft_slash_handle_fork(int sig)
{
	(void)sig;
	write(1, "Quit: 3\n", 8);
}

void	ft_start_signals(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_c_handle);
}
