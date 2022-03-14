/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:13:24 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/11 18:06:10 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/main.h"

void	ft_echo(t_shell *shell, t_token *token)
{
	bool	is_newline;

	is_newline = true;
	if (token && token ->str
		&& ft_strncmp(token->str, "-n", ft_strlen("-n")) == 0)
	{
		is_newline = false;
		while (token && token ->str
			&& ft_strncmp(token->str, "-n", ft_strlen("-n")) == 0)
			token = token->next;
	}
	while (token && token->type == ARG)
	{
		write(STDOUT_FILENO, token->str, ft_strlen(token->str));
		if (token->next && token->next->type == ARG)
			write(STDOUT_FILENO, " ", 1);
		token = token->next;
	}
	if (is_newline)
		write(STDOUT_FILENO, "\n", 1);
	shell->exit_status = ER_NON;
}
