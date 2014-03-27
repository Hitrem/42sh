/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 06:00:20 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 06:09:01 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include "exec.h"
#include "my_string.h"

t_var		*init3_var(int argc, char *param[], t_var *g_var)
{
	int			i;
	char		*nme;
	char		*name;
	char		*tmp;

	i = 1;
	while (i <= argc - 1)
	{
		nme = my_itoa(i);
		name = my_strcpy(nme);
		free(nme);
		name = realloc(name, strlen(name));
		tmp = NULL;
		tmp = my_strcpy(param[i]);
		g_var = add_var(name, tmp, g_var);
		i++;
	}
	return (g_var);
}

static int	put_params(char *param[], char *parameters, int k)
{
	int			i;
	int			j;

	i = 0;
	while (param[i + 1])
	{
		j = 0;
		while (param[i + 1][j])
		{
			parameters[k] = param[i + 1][j];
			++k;
			j++;
		}
		if (param[i + 2])
			parameters[k] = ' ';
		++k;
		i++;
	}
	return (k);
}

t_var		*init2_var(int argc, char *param[], t_var *g_var)
{
	char		*parameters;
	char		*dolat;
	int			k;

	k = 0;
	parameters = NULL;
	parameters = malloc(sizeof(char) * 128);
	k = put_params(param, parameters, k);
	parameters[k] = '\0';
	parameters = realloc(parameters, k);
	dolat = NULL;
	dolat = my_strcpy("@");
	g_var = add_var(dolat, parameters, g_var);
	return (init3_var(argc, param, g_var));
}

t_var		*init_var(int argc, char *param[])
{
	t_var	*g_var;
	char	*pid;
	char	*doldol;
	char	*value;
	char	*dolinter;

	g_var = NULL;
	g_var = malloc(sizeof(t_var));
	g_var->name = NULL;
	g_var->name = my_strcpy("#");
	g_var->val = my_itoa(argc - 1);
	g_var->next = NULL;
	pid = my_itoa(getpid());
	doldol = NULL;
	doldol = my_strcpy("$");
	g_var = add_var(doldol, pid, g_var);
	value = my_itoa(0);
	dolinter = NULL;
	dolinter = my_strcpy("?");
	g_var = add_var(dolinter, value, g_var);
	return (init2_var(argc, param, g_var));
}
