/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_convers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:31:03 by gkelsie           #+#    #+#             */
/*   Updated: 2021/12/12 21:13:40 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static int	check_command(char *str)
{
	if (ft_strncmp(str, "<<", ft_strlen("<<")) == 0)
		return (DOBINP);
	if (ft_strncmp(str, "<", ft_strlen("<")) == 0)
		return (INPUT);
	if (ft_strncmp(str, ">>", ft_strlen(">>")) == 0)
		return (APPEND);
	if (ft_strncmp(str, ">", ft_strlen(">")) == 0)
		return (TRUNC);
	if (ft_strncmp(str, "|", ft_strlen("|")) == 0)
		return (PIPE);
	return (EMPTY);
}

static void	token_init(t_token *tmp, int i)
{
	if (i == 0 && check_command(tmp->str) == EMPTY)
		tmp->type = CMD;
	else if (i == 0 && check_command(tmp->str) != EMPTY)
		tmp->type = check_command(tmp->str);
	else if (check_command(tmp->prev->str) == PIPE
		&& check_command(tmp->str) == EMPTY)
		tmp->type = CMD;
	else if (check_command(tmp->str) != EMPTY)
		tmp->type = check_command(tmp->str);
	else
		tmp->type = ARG;
}

t_token	*ft_conv_to_struct(char **coms, t_token **fin_coms)
{
	int		i;
	t_token	*head;
	t_token	*tmp;

	i = -1;
	while (coms[++i])
	{
		tmp = ft_create_token(coms[i]);
		if (tmp == NULL)
			ft_malloc_error();
		if (i == 0)
			head = tmp;
		else
			ft_tokenadd_back(&head, tmp);
		if (tmp->str)
			token_init(tmp, i);
	}
	if (fin_coms == NULL)
		return (head);
	ft_tokenadd_back(fin_coms, head);
	return (*fin_coms);
}
