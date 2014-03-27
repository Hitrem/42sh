/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   while_until.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 23:57:17 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 06:04:43 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "exec.h"

int		exec_until(t_ast *ast)
{
	while (type_node(ast->first_son) == 1 && g_pid_loop->bang == 0)
		type_node(ast->first_son->brother);
	if (g_pid_loop->bang == 1)
		g_pid_loop->bang = 0;
	ast->return_value = 0;
	g_pid_loop->return_value = 0;
	return (g_pid_loop->return_value);
}

int		exec_while(t_ast *ast)
{
	if (ast->token->type == UNTIL)
		exec_until(ast);
	while (type_node(ast->first_son) == 0 && g_pid_loop->bang == 0)
		type_node(ast->first_son->brother);
	if (g_pid_loop->bang == 1)
		g_pid_loop->bang = 0;
	ast->return_value = 0;
	g_pid_loop->return_value = 0;
	return (g_pid_loop->return_value);
}
