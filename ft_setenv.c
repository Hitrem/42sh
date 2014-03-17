/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 16:21:36 by pferry            #+#    #+#             */
/*   Updated: 2014/01/31 14:16:52 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	**ft_setenv(char **save, char **env, int add, int i)
{
	char	**new;

	if (!save[1] || !save[2])
		return (ft_putstr_fd("Not enough args.\n", 2), env);
	new = ft_tabnew(ft_tablen(env) + 1);
	while (env[i])
	{
		if (ft_strnstr(env[i], save[1], ft_strlen(save[1])) == env[i])
		{
			new[i++] = ft_strjoin(ft_strjoin(save[1], "="), save[2]);
			add = 0;
		}
		new[i] = ft_strdup(env[i]);
		i++;
	}
	if (add == 1)
		new[i] = ft_strjoin(ft_strjoin(save[1], "="), save[2]);
	new[i + add] = 0;
	return (new);
}

char	**ft_unsetenv(char **save, char **env)
{
	int		i1;
	int		i2;
	char	**new;

	i1 = 0;
	i2 = 0;
	new = (char **)malloc(sizeof(char *) * ft_tablen(env));
	if (new == NULL)
		return (NULL);
	if (!save[1])
		return (ft_putstr_fd("Not enough args.\n", 2), env);
	while (env[i1])
	{

		if (ft_strnstr(env[i1], save[1], ft_strlen(save[1])) != env[i1])
			new[i2++] = ft_strdup(env[i1]);
		i1++;
	}
	new[i2] = 0;
	return (new);
}

void	ft_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}
