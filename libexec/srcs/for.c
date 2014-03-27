/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 20:37:07 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 02:41:51 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char	**give_values(int i, int j, char *value)
{
	int			k;
	char		**values;

	values = malloc(sizeof(char*) * 5);
	k = 0;
	while (value[k])
	{
		if (value[k] == ' ')
		{
			++i;
			j = 0;
		}
		else
		{
			values[i] = realloc(values[i], j + 1);
			values[i][j] = value[k];
			++j;
			values[i][j] = '\0';
		}
		k++;
	}
	values[i + 1] = NULL;
	return (values);
}

static void	case_dol_at(t_ast *ast, char *name)
{
	int			s;
	char		*value;
	int			i;
	int			j;
	char		**values;

	value = find_var("@", g_var);
	i = 0;
	j = 0;
	values = give_values(i, j, value);
	s = 0;
	while (values[s])
	{
		g_var = add_var(name, values[s], g_var);
		type_node(ast->first_son->brother->brother);
		s++;
	}
}

static void	not_an_arg(t_ast *ast, char *name, t_ast *tmp)
{
	char	*val;
	char	*val2;

	val = malloc(sizeof(char) * strlen(tmp->token->token));
	val = my_strcpy(tmp->token->token);
	g_var = add_var(name, val, g_var);
	type_node(ast->first_son->brother->brother);
	tmp = tmp->brother;
	while (tmp)
	{
		val2 = malloc(sizeof(char) * strlen(tmp->token->token));
		val2 = my_strcpy(tmp->token->token);
		g_var = add_var(name, val2, g_var);
		type_node(ast->first_son->brother->brother);
		tmp = tmp->brother;
	}
}

int			exec_for(t_ast *ast)
{
	t_ast	*tmp;
	char	*name;

	if (ast->first_son->brother->brother == NULL)
		return (0);
	name = malloc(126);
	name = my_strcpy(ast->first_son->token->token);
	tmp = ast->first_son->brother->first_son;
	if (strcmp(tmp->token->token, "@") != 0)
		not_an_arg(ast, name, tmp);
	else
		case_dol_at(ast, name);
	g_pid_loop->return_value = 0;
	return (0);
}
