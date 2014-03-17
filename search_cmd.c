/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:59:39 by pferry            #+#    #+#             */
/*   Updated: 2014/01/24 15:59:44 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	search_cmd(char **cmd, char **env, size_t i)
{
	char	**path;
	char	*tmp1;
	char	*tmp2;

	path = NULL;
	while (env[i] && path == NULL)
	{
		if (ft_strnstr(env[i], "PATH=", 5) == env[i])
		{
			tmp1 = ft_strsub(env[i], 5, ft_strlen(env[i]) - 5);
			path = ft_strsplit(tmp1, ':');
			free(tmp1);
		}
		i++;
	}
	i = 0;
	execve(cmd[0], cmd, env);
	while (path && path[i] != NULL)
	{
		tmp1 = ft_strjoin(path[i++], "/");
		tmp2 = ft_strjoin(tmp1, cmd[0]);
		free(tmp1);
		execve(tmp2, cmd, env);
		free(tmp2);
	}
}
