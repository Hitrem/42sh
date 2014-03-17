/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 17:43:01 by pferry            #+#    #+#             */
/*   Updated: 2014/01/26 17:58:37 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	**ft_pipe_cmd(char **save, char **env, char *next)
{
	int			pfd[2];
	pid_t		pid;
	pid_t		pidagain;
	int			status;

	if ((pid = fork()) < 0)
		ft_error("Error with: fork", "");
	if (pid == 0)
	{
		if ((pidagain = fork()) < 0 || pipe(pfd) == -1)
			ft_error("Error with: fork", "");
		if (pidagain == 0)
		{
			close(pfd[0]);
			dup2(pfd[1], 1);
			close(pfd[1]);
			search_cmd(save, env, 0);
			ft_putstr_fd(save[0], 2);
			ft_putendl_fd(": command not found.", 2); 
			exit(1);
		}
		else
		{
			free(save);
			save = ft_strsplit(next, ' ');
			close(pfd[1]);
			dup2(pfd[0], 0);
			close(pfd[0]);
			if (save[0][0] == '\0')
				return (env);
			if (ft_strcmp(save[0], "exit") == 0)
				exit(0);
			else if (ft_strcmp(save[0], "env") == 0)
				ft_env(env);
			else if (ft_strcmp(save[0], "unsetenv") == 0)
				env = ft_unsetenv(save, env);
			else if (ft_strcmp(save[0], "setenv") == 0)
				env = ft_setenv(save, env, 1, 0);
			else if (ft_strcmp(save[0], "cd") == 0)
				env = ft_cd(save, env);
			else
			{
				search_cmd(save, env, 0);
				ft_putstr_fd(save[0], 2);
				ft_putendl_fd(": command not found.", 2);
				exit(1);
			}
		}
		exit(1);
	}
	else
	{
		wait(&status);
		return (env);
	}
	return (env);
}

