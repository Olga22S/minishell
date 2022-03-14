/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_tokening.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:12:04 by gkelsie           #+#    #+#             */
/*   Updated: 2021/12/13 14:26:17 by a1111            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static bool	free_process_tokening(char *com, char **coms)
{
	int		i;

	i = -1;
	if (com != NULL)
		free(com);
	if (coms != NULL)
	{
		while (coms[++i])
			free(coms[i]);
		free(coms);
	}
	return (false);
}

static char	**tokens_free(char **coms)
{
	int			i;

	i = -1;
	if (coms)
	{
		while (coms[++i])
			free(coms[i]);
		free(coms);
		coms = NULL;
	}
	return (coms);
}

static char	**token_put(char *str, int amount)
{
	t_parse		parse;
	char		**coms;

	parse = ft_parse_init();
	coms = (char **)ft_calloc(amount + 1, sizeof(char *));
	if (coms == NULL)
		ft_malloc_error();
	while (str[parse.i])
	{
		ft_set_quote_status(&parse.quotes, str[parse.i]);
		if (str[parse.i] == '\\' && parse.quotes.dble == true
			&& str[parse.i + 1] == '\0')
			parse.i++;
		if ((ft_strchr_bo("<>| \t", str[parse.i]) && parse.quotes.dble == false
				&& parse.quotes.solo == false) || str[parse.i + 1] == '\0')
		{
			if (ft_token_new(coms, &parse, str) == false)
				return (tokens_free(coms));
			if (parse.flag == true)
				return (coms);
		}
		else
			parse.i++;
	}
	return (coms);
}

bool	ft_process_tokening(t_shell *shell, char **commands, t_envs_lst *env)
{
	char	**coms;
	char	*com;
	t_parse	parse;
	t_token	*fin_coms;

	fin_coms = NULL;
	parse = ft_parse_init();
	while (commands[parse.i])
	{
		com = ft_trim_tabulation(commands[parse.i++]);
		if (com == NULL)
			ft_malloc_error();
		parse.token_amount = ft_token_amount(com);
		coms = token_put(com, parse.token_amount);
		if (coms == NULL)
			ft_malloc_error();
		ft_low_up_token(coms);
		fin_coms = ft_conv_to_struct(coms, &fin_coms);
		free_process_tokening(com, coms);
	}
	ft_quotes_plus(fin_coms);
	ft_addon_token(fin_coms);
	ft_execute_token(shell, fin_coms, env);
	ft_token_struct_free(fin_coms);
	return (true);
}
