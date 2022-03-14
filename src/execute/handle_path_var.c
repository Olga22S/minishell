/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_path_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 22:52:26 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/09 16:43:06 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

void	ft_free_paths(char **paths, char *cmd_with_slash)
{
	int	i;

	i = -1;
	while (paths && paths[++i])
		free(paths[i]);
	free(paths);
	free(cmd_with_slash);
}
