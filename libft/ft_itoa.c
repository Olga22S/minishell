/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:47:30 by crendeha          #+#    #+#             */
/*   Updated: 2021/10/06 00:02:13 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_of_digits(int n)
{
	int	digits;

	if (n <= 0)
		digits = 1;
	else
		digits = 0;
	while (n != 0)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

static void	reverse_str(char *s, int start, int end)
{
	char	temp;

	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		start++;
		end--;
	}
}

char	*ft_itoa(int n)
{
	long int	num;
	int			digits;
	char		*s;
	int			i;

	digits = get_num_of_digits(n);
	num = n;
	if (n <= 0)
		num *= (-1);
	s = malloc(digits + 1);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (num != 0)
	{
		s[i++] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		s[i++] = '-';
	else if (n == 0)
		s[i++] = '0';
	s[i] = '\0';
	reverse_str(s, 0, i - 1);
	return (s);
}
