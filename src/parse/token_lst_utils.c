/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:28:33 by gkelsie           #+#    #+#             */
/*   Updated: 2021/12/08 13:17:47 by a1111            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

t_token	*ft_create_token(char *content)
{
	t_token	*element;

	element = (t_token *)ft_calloc(1, sizeof(t_token));
	if (element == NULL)
		return (element);
	else
	{
		element->str = ft_strdup(content);
		if (element->str == NULL)
		{
			free(element);
			element = NULL;
			return (NULL);
		}
	}
	return (element);
}

void	ft_tokenadd_back(t_token **lst, t_token *new)
{
	t_token	*curr;
	t_token	*tmp;

	curr = *lst;
	if (curr == NULL)
		*lst = new;
	else
	{
		while (curr->next)
			curr = curr->next;
		tmp = curr;
		curr->next = new;
		tmp = curr->next;
		tmp->prev = curr;
	}
}

void	ft_token_struct_free(t_token *lst)
{
	t_token	*tmp;

	while (lst != NULL)
	{
		tmp = lst->next;
		if (lst->str != NULL)
			free(lst->str);
		if (lst != NULL)
			free(lst);
		lst = tmp;
	}
}
