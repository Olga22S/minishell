/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:50:42 by gkelsie           #+#    #+#             */
/*   Updated: 2021/12/10 12:37:40 by a1111            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static bool	check_string(char *str, t_quotes *quotes, int *i, char *user)
{
	static char	*pool_symbols = "\\<>|;";

	ft_set_quote_status(quotes, str[*i]);
	if (str[*i] == '\\' && quotes->dble == true)
		(*i)++;
	else if (ft_strchr_bo(pool_symbols, str[*i]) == true
		&& ft_is_outside_quotes(quotes) == true)
		if (ft_check_seps(str, i, user) == false
			|| ft_check_redirect(str, i, user) == false)
			return (false);
	return (true);
}

bool	ft_preparse(char *str, char *user)
{
	int			i;
	t_quotes	quotes;

	quotes = ft_quotes_init();
	i = 0;
	while (str[i])
	{
		if (check_string(str, &quotes, &i, user) == false)
			return (false);
		if (str[i] != '\0')
			i++;
	}
	return (true);
}
