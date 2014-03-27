/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_var_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:30:51 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 06:12:40 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <libgen.h>
#include <unistd.h>
#include "local_var.h"
#include "exec.h"
#include "my_fnmatch.h"

t_var			*change_value(char *name, char *value, t_var *g_var)
{
	if (strcmp(name, g_var->name) == 0)
	{
		g_var->val = value;
		return (g_var);
	}
	return (change_value(name, value, g_var->next));
}

char			*get_var_name(char *str)
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

char			*get_var_value(char *str)
{
	int		double_quote;
	size_t	i;
	size_t	index;
	char	*var_val;

	double_quote = 0;
	i = 0;
	index = 0;
	var_val = malloc(sizeof(char) * 1024);
	while (str[i] != '=')
		++i;
	if (str[++i] == '"')
	{
		double_quote = 1;
		++i;
	}
	i += 0;
	while (str[i] >= 32 && str[i] <= 126)
	{
		var_val[index++] = str[i];
		i++;
	}
	var_val[index - 1] = (double_quote) ? '\0' : var_val[index - 1];
	var_val[index] = (!double_quote) ? '\0' : var_val[index];
	return (var_val);
}

char			*reload_prompt(char *str)
{
	return (substitute(str));
}
