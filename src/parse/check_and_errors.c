/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:26:16 by gkelsie           #+#    #+#             */
/*   Updated: 2021/12/10 12:46:49 by a1111            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static bool	error_syntax_token(char ch, char *name)
{
	write(2, name, ft_strlen(name) - 1);
	if (ch == '\0')
		write(2, ": these commands are not supported\n", 35);
	else if (ch == '\n')
		write(2, ": syntax error near unexpected token `newline'\n", 47);
	else if (ch == ';')
		write(2, ": syntax error near unexpected token `;'\n", 41);
	else if (ch == '\\')
		write(2, ": syntax error near unexpected token `\\'\n", 41);
	else if (ch == '|')
		write(2, ": syntax error near unexpected token `|'\n", 41);
	return (false);
}

static bool	error_redirect_check(int redirect_first, int redirect_second,
								char *name)
{
	if (redirect_first != EMPTY && redirect_second != EMPTY)
	{
		write(2, name, ft_strlen(name) - 1);
		if (redirect_second == OUT_TWO)
			write(2, ": syntax error near unexpected token `>>'\n", 42);
		else if (redirect_second == OUT)
			write(2, ": syntax error near unexpected token `>'\n", 41);
		else if (redirect_second == IN)
			write(2, ": syntax error near unexpected token `<'\n", 41);
		else
			write(2, ": syntax error near unexpected token `newline'\n", 47);
		return (false);
	}
	return (true);
}

static int	redirect_type(char *str, int i)
{
	if (str[i] == '<' && str[i + 1] == '<')
		return (IN_TWO);
	if (str[i] == '<')
		return (IN);
	if (str[i] == '>' && str[i + 1] == '>')
		return (OUT_TWO);
	if (str[i] == '>')
		return (OUT);
	return (EMPTY);
}

bool	ft_check_seps(char *str, int *i, char *name)
{
	static char	*pool_symbols = ";|";

	if (str[*i] == ';' || str[*i] == '|' || str[*i] == '\\')
	{
		if (ft_strchr_bo(pool_symbols, str[*i]) == true && (ft_strlen(str) == 1
				|| *i == 0))
			return (error_syntax_token(str[*i], name));
		if (str[*i] == '\\')
			return (error_syntax_token(str[*i], name));
		while (ft_is_whitespace(str[*i + 1]))
			(*i)++;
		if (str[*i] == '|' && str[*i + 1] == '\0')
			return (error_syntax_token(str[*i + 1], name));
		if (str[*i + 1] == '|' || str[*i + 1] == ';')
			return (error_syntax_token(str[*i + 1], name));
		if (str[*i] == '\\' && str[*i + 1] == '\0')
			return (error_syntax_token(str[*i], name));
	}
	return (true);
}

bool	ft_check_redirect(char *str, int *i, char *name)
{
	int		redirect_first;
	int		redirect_second;
	int		j;

	redirect_first = EMPTY;
	redirect_second = EMPTY;
	if (str[*i] == '<' || str[*i] == '>')
	{
		redirect_first = redirect_type(str, *i);
		(*i)++;
		if (redirect_first == OUT_TWO || redirect_first == IN_TWO)
			(*i)++;
		j = *i;
		while (ft_is_whitespace(str[j]))
			j++;
		if (str[j] == '\0' || str[j] == ';')
			return (error_syntax_token('\n', name));
		redirect_second = redirect_type(str, j);
		if (error_redirect_check(redirect_first,
				redirect_second, name) == false)
			return (false);
	}
	return (true);
}
