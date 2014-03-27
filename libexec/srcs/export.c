/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:21:33 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 12:22:33 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "exec.h"
#include "export.h"
#include "my_fnmatch.h"
#include "local_var.h"

static char		*get_export_name(char *str)
{
	size_t	i;
	char	*var_name;

	var_name = malloc(sizeof(char) * 128);
	i = 0;
	while (str[i] != '=')
	{
		var_name[i] = str[i];
		i++;
	}
	var_name[i] = '\0';
	return (var_name);
}

static char		*get_export_val(char *str)
{
	size_t	i;
	size_t	index;
	char	*var_val;

	i = 0;
	index = 0;
	var_val = malloc(sizeof(char) * 1024);
	while (str[i] != '=')
		++i;
	i += 1;
	while (str[i] >= 32 && str[i] <= 126)
	{
		var_val[index++] = str[i];
		i++;
	}
	var_val[index] = '\0';
	return (var_val);
}

static void		print_environ(void)
{
	size_t			i;
	char			*var_name;
	char			*var_val;

	var_name = NULL;
	var_val = NULL;
	i = 0;
	while (environ && environ[i] != NULL)
	{
		var_name = get_export_name(environ[i]);
		var_val = get_export_val(environ[i]);
		if (strcmp(var_val, ""))
			printf("export %s=\"%s\"\n", var_name, var_val);
		else
			printf("export %s\n", var_name);
		free(var_name);
		free(var_val);
		i++;
	}
}

static void		ft_func1(t_ast **arg1, t_ast **arg2, t_ast *node)
{
	*arg1 = node->brother->first_son;
	*arg2 = node->brother->first_son->brother;
}

int				my_export(t_ast *node)
{
	t_ast	*arg1;
	t_ast	*arg2;

	arg1 = NULL;
	arg2 = NULL;
	if (node->brother && node->brother->first_son)
		ft_func1(&arg1, &arg2, node);
	else
	{
		if (node->brother)
			arg1 = node->brother;
		if (node->brother && node->brother->brother)
			arg2 = node->brother->brother;
	}
	if (!arg1 || (arg1 && !strcmp(arg1->token->token, "-p") && arg2 == NULL)
			|| (arg1 && !strcmp(arg1->token->token, "-n") && arg2 == NULL))
		print_environ();
	else if (arg1 && !strcmp(arg1->token->token, "-n") && arg2 != NULL)
		unsetenv(arg2->token->token);
	else if (node->brother && node->brother->first_son)
		setenv(arg1->token->token, arg2->token->token, 1);
	else if (arg1 && arg2 == NULL)
		setenv(arg1->token->token, "", 1);
	g_pid_loop->return_value = 0;
	return (0);
}
