/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_hand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:12:04 by gkelsie           #+#    #+#             */
/*   Updated: 2021/12/12 21:13:40 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static int	new_size_str(char *str, int count)
{
	int			i;
	t_quotes	quotes;

	i = -1;
	quotes = ft_quotes_init();
	while (str[++i])
	{
		if (ft_set_quote_status(&quotes, str[i]) == false)
		{
			if (str[i] == '\\' && quotes.dble == true)
			{
				if (str[i + 1] == '\"' || str[i + 1] == '$'
					|| str[i + 1] == '`' || str[i + 1] == '\\')
				{
					count++;
					i++;
				}
				else
					count++;
			}
			else
				count++;
		}
	}
	return (count);
}

static char	*bye_quotes(char *str, t_quotes *quotes, int i, int j)
{
	char		*new_str;
	int			new_size;

	new_size = new_size_str(str, 0);
	new_str = (char *)ft_calloc(new_size + 1, sizeof(char));
	if (new_str == NULL)
		ft_malloc_error();
	while (str[++i] && j < new_size)
	{
		if (ft_set_quote_status(quotes, str[i]) == false)
		{
			if (str[i] == '\\' && quotes->dble == true)
			{
				if (str[i + 1] != '"' && str[i + 1] != '`'
					&& str[i + 1] != '$' && str[i + 1] != '\\')
				{
					new_str[j++] = '\\';
				}	
				i++;
			}
			new_str[j++] = str[i];
		}
	}
	new_str[j] = '\0';
	return (new_str);
}

void	ft_quotes_plus(t_token *coms)
{
	int			i;
	char		*tmp;
	t_quotes	quotes;

	while (coms)
	{
		i = -1;
		while (coms->str[++i])
		{
			if (ft_strchr_bo("\"\'", coms->str[i]) == true)
			{
				tmp = coms->str;
				quotes = ft_quotes_init();
				coms->str = bye_quotes(tmp, &quotes, -1, 0);
				free(tmp);
				break ;
			}
		}
		coms = coms->next;
	}	
}
