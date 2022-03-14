/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:54:49 by a1111             #+#    #+#             */
/*   Updated: 2021/12/11 14:22:29 by a1111            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

void	ft_sig_ignore(int sig)
{
	(void)sig;
}

void	ft_sig_heredoc(int sig)
{
	(void)sig;
	exit(ER_MAIN);
}

void	ft_sig_empty(int sig)
{
	(void)sig;
	write(1, "\n", 1);
}
