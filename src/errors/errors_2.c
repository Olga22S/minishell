/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:29:06 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/12 22:32:12 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

void	ft_execve_error(void)
{
	ft_putstr_fd("Process terminated with execve error\n", STDERR_FILENO);
	exit(ER_EXECVE);
}

void	ft_path_error(void)
{
	ft_putstr_fd("Process terminated with path error\n", STDERR_FILENO);
	exit(ER_PATH);
}

void	ft_pipe_error(void)
{
	ft_putstr_fd("Process terminated with pipe error\n", STDERR_FILENO);
	exit(ER_PIPE);
}
