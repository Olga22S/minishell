/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:22:38 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/12 21:08:12 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/main.h"

static bool	check_eq_sign(t_token *token)
{
	int	i;

	i = 0;
	while (token->str && token->str[i] != '\0')
	{
		if (token->str[i] == '=')
			return (true);
		i++;
	}
	return (false);
}

static bool	check_key_validity(t_token *token)
{
	int	i;

	i = 0;
	while (token->str && token->str[i] != '\0' && token->str[i] != '=')
		i++;
	return (i > 0);
}

static void	handle_existing_key(t_envs_lst **envs, t_token *token)
{
	int		i;
	char	*key;

	i = 0;
	while (token->str && token->str[i] != '=')
		i++;
	key = ft_substr(token->str, 0, i);
	if (key == NULL)
		ft_malloc_error();
	if (ft_search_env_var(envs, key) != NULL)
		ft_remove_env_var(envs, key);
	free(key);
}

static void	handle_empty_export(t_envs_lst **envs)
{
	t_envs_lst	*curr;
	char		**keys;
	int			i;

	if (envs == NULL || *envs == NULL)
		return ;
	curr = *envs;
	i = -1;
	keys = ft_get_sorted_keys(envs);
	while (keys && keys[++i])
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(keys[i], STDOUT_FILENO);
		ft_putstr_fd("=", STDOUT_FILENO);
		ft_putstr_fd(ft_search_env_var(envs, keys[i]), STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		curr = curr->next;
	}
	if (keys)
		ft_free_sorted_keys(keys, i);
}

void	ft_export(t_shell *shell, t_envs_lst **envs, t_token *token)
{
	if (token == NULL || token->type != ARG)
		handle_empty_export(envs);
	else
	{		
		while (token && token->str && token->type == ARG)
		{
			if (!ft_check_env_syntax(token->str) || !check_key_validity(token))
				ft_handle_export_error(shell, envs, token);
			else if (!check_eq_sign(token))
				shell->exit_status = ER_NON;
			else
			{
				handle_existing_key(envs, token);
				ft_add_env_var(envs, token->str);
				shell->exit_status = ER_NON;
			}
			token = token->next;
		}
	}
}
