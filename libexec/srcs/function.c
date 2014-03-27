/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:21:33 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 03:19:03 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		execute_funct(char *name)
{
	t_funct *tmp;

	tmp = g_funct;
	while (strcmp(name, g_funct->name) != 0)
		tmp = tmp->next;
	return (statements(tmp->function));
}

int		find_funct(char *name, t_funct *g_funct)
{
	if (g_funct == NULL)
		return (0);
	if (strcmp(name, g_funct->name) == 0)
		return (1);
	return (find_funct(name, g_funct->next));
}

void	free_funct(void)
{
	t_funct *tmp;

	while (g_funct)
	{
		tmp = g_funct->next;
		free(g_funct->name);
		free(g_funct);
		g_funct = tmp;
	}
}

t_funct *new_funct(t_ast *node)
{
	t_funct *new;

	new = malloc(sizeof(t_funct));
	new->name = my_strcpy(node->first_son->token->token);
	new->function = get_ast_copy(node->first_son->brother);
	new->next = g_funct;
	node->return_value = 0;
	return (new);
}
