/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:57:57 by pferry            #+#    #+#             */
/*   Updated: 2014/01/31 13:26:48 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	*ft_find_home(char **env)
{
	int		i;
	char	*home;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "HOME=", 5) == env[i])
			home = ft_strsub(env[i], 5, ft_strlen(env[i]) - 5);
		i++;
	}
	return (ft_strjoin("PWD=", home));
}

static char	*ft_find_oldpwd(char **env)
{
	int		i;
	char	*oldpwd;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "OLDPWD=", 7) == env[i])
			oldpwd = ft_strsub(env[i], 7, ft_strlen(env[i]) - 7);
		i++;
	}
	return (ft_strjoin("PWD=", oldpwd));
}

static char	*ft_find_directory(char **save, char *pwd)
{
	char	*path;
	char	*new;
	char	*tmp;

	if (save[1][0] == '/')
		return (ft_strjoin("PWD=", save[1]));
	else
	{
		path = ft_strjoin(ft_strchr(pwd, '=') + 1, ft_strjoin("/", save[1]));
		chdir(path);
		tmp = (char*)malloc(sizeof(char) * ft_strlen(path) + 1);
		if (tmp == NULL)
			ft_error("cd: malloc issue");
		tmp = getcwd(path, 1024);
		new = ft_strjoin("PWD=", tmp);
		return (new);
	}
}

char		**ft_cd(char **save, char **env)
{
	int		i;
	char	*tmp;

	if (save[1] && save[1][0] != '-')
		ft_get_info(save[1], 0, 0);
	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PWD=", 4) == env[i])
		{
			tmp = ft_strdup(env[i]);
			if (!save[1])
				env[i] = ft_find_home(env);
			else if (save[1][0] == '-')
				env[i] = ft_find_oldpwd(env);
			else
				env[i] = ft_find_directory(save, env[i]);
			chdir(ft_strchr(env[i], '=') + 1);
		}
		if (ft_strnstr(env[i], "OLDPWD=", 7) == env[i])
			env[i] = ft_strjoin("OLD", tmp);
		i++;
	}
	return (env);
}
