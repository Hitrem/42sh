/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:59:22 by pferry            #+#    #+#             */
/*   Updated: 2014/03/05 17:46:40 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_error(char *name)
{
	ft_putstr_fd("Error in: ", 2);
	ft_putendl_fd(name, 2);
	exit(-1);
}

void	ft_lstprint(t_list *lst)
{
	while (lst)
	{
		ft_putendl(lst->content);
		lst = lst->next;
	}
}

int		main(int argc, char **argv, char **environ)
{
	char	**env;
	char	*line;

	argv[argc - 1] = argv[argc - 1];
	ft_envinit();
	env = ft_tabdub(environ);
	while (42)
	{
		ft_putstr("$>");
		line = ft_keyboard();
		ft_putchar('\n');
		if (line[0] == '\0')
			continue;
		if (!ft_strcmp(line, "exit"))
			break;
		ft_simple_cmd(ft_strsplit(line, ' '), env);
	}
	ft_envreset(0);
	return (0);
}

char	**ft_simple_cmd(char **save, char **env)
{
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
		ft_cmd(save, env);
	return (env);
}

void	ft_cmd(char **save, char **env)
{
	pid_t	pid;
	int		status;

	if ((pid = fork()) < 0)
		ft_putendl_fd("Error with: fork", 2);
	if (pid == 0)
	{
		search_cmd(save, env, 0);
		ft_putstr_fd(save[0], 2);
		ft_putendl_fd(": command not found.", 2); 
		exit(1);
	}
	else
	{
		wait(&status);
	}
}
