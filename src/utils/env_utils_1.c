/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:42:45 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/12 21:13:40 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static t_env_variable	*create_new_var(char *line)
{
	int				i;
	int				j;
	t_env_variable	*new;

	new = (t_env_variable *) malloc(sizeof(t_env_variable));
	if (new == NULL)
		ft_malloc_error();
	i = 0;
	while (line[i] != '=')
		i++;
	new->key = ft_substr(line, 0, i);
	if (new->key == NULL)
		ft_malloc_error();
	j = i + 1;
	while (line[j] != '\0' && line[j] != '\n')
		j++;
	new->val = ft_substr(line, i + 1, j - i);
	if (new->val == NULL)
		ft_malloc_error();
	return (new);
}

static t_envs_lst	*create_env_lst_el(char *line)
{
	t_envs_lst	*new;

	new = (t_envs_lst *) malloc(sizeof(t_envs_lst));
	if (new == NULL)
		ft_malloc_error();
	new->data = create_new_var(line);
	new->next = NULL;
	return (new);
}

static void	free_env_var(t_envs_lst	*curr)
{
	free(curr->data->key);
	free(curr->data->val);
	free(curr->data);
	free(curr);
}

void	ft_add_env_var(t_envs_lst **envs, char *line)
{
	t_envs_lst	*curr;

	if (line == NULL)
		return ;
	if (*envs == NULL)
		*envs = create_env_lst_el(line);
	else
	{
		curr = *envs;
		while (curr->next)
			curr = curr->next;
		curr->next = create_env_lst_el(line);
	}
}

void	ft_remove_env_var(t_envs_lst **envs, char *key)
{
	t_envs_lst	*curr;
	t_envs_lst	*tmp;

	if (envs == NULL || *envs == NULL || key == NULL)
		return ;
	curr = *envs;
	if (ft_strncmp(curr->data->key, key, ft_strlen(key)) == 0)
	{
		tmp = curr->next;
		free_env_var(curr);
		*envs = tmp;
	}
	while (curr && curr->next != NULL)
	{
		if (ft_strncmp(key, curr->next->data->key,
				ft_strlen(key)) == 0)
		{
			tmp = curr->next->next;
			free_env_var(curr->next);
			curr->next = tmp;
			return ;
		}
		curr = curr->next;
	}
	return ;
}
