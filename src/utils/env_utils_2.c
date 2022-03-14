/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:42:45 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/13 13:46:29 by a1111            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

char	*ft_search_env_var(t_envs_lst **envs, char *key)
{
	t_envs_lst	*curr;

	if (envs == NULL || *envs == NULL || key == NULL)
		return (NULL);
	curr = *envs;
	while (curr)
	{
		if (ft_strncmp(curr->data->key, key,
				ft_strlen(curr->data->key)) == 0)
			return (curr->data->val);
		curr = curr->next;
	}
	return (NULL);
}

void	ft_free_envs(t_envs_lst **envs)
{
	t_envs_lst	*tmp;

	while (envs && *envs)
	{
		tmp = (*envs)->next;
		ft_remove_env_var(envs, (*envs)->data->key);
		*envs = tmp;
	}
}

void	ft_update_shlvl(t_shell *shell, t_token *token, t_envs_lst **env)
{
	char	*line;
	char	*lvl;

	if (ft_strnstr(token->str, "minishell", ft_strlen(token->str)) != NULL)
	{
		shell->shlvl++;
		lvl = ft_itoa(shell->shlvl);
		if (lvl == NULL)
			ft_malloc_error();
		line = ft_strjoin("SHLVL=", ft_itoa(shell->shlvl));
		if (line == NULL)
			ft_malloc_error();
		ft_remove_env_var(env, "SHLVL");
		ft_add_env_var(env, line);
		free(line);
		free(lvl);
	}
}
