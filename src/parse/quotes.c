/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:23:42 by gkelsie           #+#    #+#             */
/*   Updated: 2021/12/01 14:24:36 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

bool	ft_set_quote_status(t_quotes *quotes, char ch)
{
	if (ch == '\'' && quotes->solo == true)
		quotes->solo = false;
	else if (ch == '\'' && quotes->dble == false)
		quotes->solo = true;
	else if (ch == '"' && quotes->dble == true)
		quotes->dble = false;
	else if (ch == '"' && quotes->solo == false)
		quotes->dble = true;
	else
		return (false);
	return (true);
}

bool	ft_is_outside_quotes(t_quotes *quotes)
{
	return (quotes->dble == false && quotes->solo == false);
}
