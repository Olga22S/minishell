/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:38:02 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/10 01:23:46 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/main.h"

void	ft_pwd(t_shell *shell)
{
	char	pwd[PATH_MAX + 1];
	char	*status;

	shell->exit_status = ER_NON;
	status = getcwd(pwd, PATH_MAX + 1);
	if (status == NULL)
		return ;
	write(STDOUT_FILENO, pwd, ft_strlen(pwd));
	write(STDOUT_FILENO, "\n", 1);
}
