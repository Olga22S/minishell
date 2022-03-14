/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:30:46 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/12 21:12:01 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

void	ft_malloc_error(void)
{
	ft_putstr_fd("Process terminated with malloc error\n", STDERR_FILENO);
	exit(ER_MAL);
}

void	ft_dup_error(void)
{
	ft_putstr_fd("Process terminated with dup error\n", STDERR_FILENO);
	exit(ER_DUP);
}

void	ft_fork_error(void)
{
	ft_putstr_fd("Process terminated with fork error\n", STDERR_FILENO);
	exit(ER_FORK);
}

void	ft_open_error(void)
{
	ft_putstr_fd("Process terminated with open error\n", STDERR_FILENO);
	exit(ER_CLOSE);
}

void	ft_close_error(void)
{
	ft_putstr_fd("Process terminated with close error\n", STDERR_FILENO);
	exit(ER_CLOSE);
}
