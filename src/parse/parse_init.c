/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:16:13 by gkelsie           #+#    #+#             */
/*   Updated: 2021/12/09 16:59:20 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

t_quotes	ft_quotes_init(void)
{
	t_quotes	quotes;

	quotes.dble = false;
	quotes.solo = false;
	return (quotes);
}

t_parse	ft_parse_init(void)
{
	t_parse	parse_data;

	parse_data.quotes = ft_quotes_init();
	parse_data.i = 0;
	parse_data.begin_str = 0;
	parse_data.pipe = 0;
	parse_data.flag = false;
	parse_data.size = 0;
	parse_data.token_amount = 0;
	parse_data.index_token = 0;
	return (parse_data);
}
