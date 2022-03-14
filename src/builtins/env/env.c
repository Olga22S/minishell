/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:08:31 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/07 02:12:48 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/main.h"

void	ft_env(t_shell *shell, t_envs_lst **envs)
{
	t_envs_lst	*curr;

	shell->exit_status = ER_NON;
	if (envs == NULL)
		return ;
	curr = *envs;
	while (curr != NULL)
	{
		write(STDOUT_FILENO, curr->data->key, ft_strlen(curr->data->key));
		write(STDOUT_FILENO, "=", 1);
		write(STDOUT_FILENO, curr->data->val, ft_strlen(curr->data->val));
		write(STDOUT_FILENO, "\n", 1);
		curr = curr->next;
	}
	return ;
}
