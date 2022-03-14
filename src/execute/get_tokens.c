/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:24:59 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/12 19:38:25 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

t_token	*ft_get_prev_token(t_token	*token)
{
	if (token && token->type >= TRUNC)
		token = token->prev;
	while (token && token->type < TRUNC)
		token = token->prev;
	return (token);
}

t_token	*ft_get_next_token(t_token	*token)
{
	if (token && token->type >= TRUNC)
		token = token->next;
	while (token && token->type < TRUNC)
		token = token->next;
	return (token);
}
