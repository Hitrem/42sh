/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 00:37:14 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 03:13:47 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser_functions.h"
#include "parser.h"

static void	free_function2(void *to_free)
{
	t_token	*tok;

	tok = to_free;
	free_token(tok);
}

static void	free_function3(void *to_free)
{
	free(to_free);
}

void		free_lists(void)
{
	if (!g_lists)
		return ;
	list_free(g_lists->tokens, free_function2);
	g_lists->tokens = NULL;
	list_free(g_lists->garbage_tokens, free_function2);
	g_lists->garbage_tokens = NULL;
	list_free(g_lists->garbage_nodes, free_function3);
	g_lists->garbage_nodes = NULL;
}

void		free_fun_lists(void)
{
	if (!g_lists)
		return ;
	list_free(g_lists->garbage_fun_tokens, free_function2);
	g_lists->garbage_fun_tokens = NULL;
	list_free(g_lists->garbage_fun_nodes, free_function3);
	g_lists->garbage_fun_nodes = NULL;
	free(g_lists);
}
