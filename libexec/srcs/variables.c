/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 23:42:47 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 07:41:00 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include "exec.h"
#include "my_string.h"

t_var		*vchange_value(char *name, char *value, t_var *g_var)
{
	if (strcmp(name, g_var->name) == 0)
	{
		g_var->val = value;
		return (g_var);
	}
	return (vchange_value(name, value, g_var->next));
}

int			var_exist(char *name, t_var *g_var)
{
	if (strcmp(name, "RANDOM") == 0)
		return (1);
	if (strcmp(name, g_var->name) == 0)
		return (1);
	if (g_var->next)
		return (var_exist(name, g_var->next));
	return (0);
}

t_var		*add_var(char *variable, char *value, t_var *g_var)
{
	t_var		*new;

	if (var_exist(variable, g_var) == 1)
	{
		g_var = vchange_value(variable, value, g_var);
		return (g_var);
	}
	new = NULL;
	new = (t_var*)malloc(sizeof(t_var));
	new->name = variable;
	new->val = value;
	new->next = g_var;
	return (new);
}

char		*find_var(char *val, t_var *g_var)
{
	if (g_var == NULL)
		return (NULL);
	if (strcmp(val, g_var->name) == 0)
		return (g_var->val);
	if (strcmp(val, "RANDOM") == 0)
		return (my_itoa(rand()));
	return (find_var(val, g_var->next));
}

t_var		*new_var(t_ast *node)
{
	t_ast	*tmp;
	char	*name;
	t_var	*new;

	tmp = NULL;
	name = my_strcpy(tmp->token->token);
	tmp = node->first_son;
	if (var_exist(tmp->token->token, g_var) == 1)
	{
		g_var = vchange_value(tmp->token->token,
				tmp->brother->token->token, g_var);
		return (g_var);
	}
	new = NULL;
	new = (t_var*)malloc(sizeof(t_var));
	new->name = NULL;
	new->name = my_strcpy(name);
	free(name);
	if (tmp->token->token[0] != '$')
		new->val = my_strcpy(tmp->brother->token->token);
	else
		new->val = find_var(tmp->token->token, g_var);
	new->next = g_var;
	node->return_value = 0;
	return (new);
}
