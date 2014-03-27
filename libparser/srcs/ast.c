/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 18:46:14 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 03:13:49 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "parser_functions.h"
#include "parser.h"

t_ast			*init_node(t_token *token, t_ast *brother, t_ast *first_son)
{
	t_ast		*new;

	new = (t_ast*)malloc(sizeof(t_ast));
	new->token = token;
	new->return_value = -1;
	new->brother = brother;
	new->first_son = first_son;
	g_lists->garbage_nodes = list_append(g_lists->garbage_nodes, new);
	return (new);
}

t_ast			*add_to_sons(t_ast *ast, int nb_of_sons, t_ast *new_son, ...)
{
	va_list		list;
	int			i;
	t_ast		*tmp;

	va_start(list, new_son);
	tmp = ast->first_son;
	if (tmp)
	{
		while (tmp->brother)
			tmp = tmp->brother;
		tmp->brother = new_son;
		tmp = tmp->brother;
	}
	else
	{
		ast->first_son = new_son;
		tmp = ast->first_son;
	}
	i = 1;
	while (i++ < nb_of_sons)
	{
		tmp->brother = va_arg(list, t_ast *);
		tmp = tmp->brother;
	}
	return (ast);
}

t_ast			*add_son(t_ast *ast, t_ast *new_son)
{
	return (add_to_sons(ast, 1, new_son));
}

t_ast			*get_ast_copy(t_ast *ast)
{
	t_token		*tok;
	t_ast		*node;

	if (!ast)
		return (NULL);
	tok = get_token_copy(ast->token);
	g_lists->garbage_fun_tokens = list_append(g_lists->garbage_fun_tokens, tok);
	node = (t_ast*)malloc(sizeof(t_ast));
	node->token = tok;
	node->brother = get_ast_copy(ast->brother);
	add_son(node, get_ast_copy(ast->first_son));
	g_lists->garbage_fun_nodes = list_append(g_lists->garbage_fun_nodes, node);
	return (node);
}
