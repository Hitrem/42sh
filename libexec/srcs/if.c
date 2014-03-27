/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:21:33 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/26 20:53:35 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	go_loop(t_ast *ast, t_ast *tmp)
{
	g_pid_loop->return_value = 1;
	if (ast->first_son->brother->brother)
	{
		type_node(tmp->brother);
		return (g_pid_loop->return_value);
	}
	g_pid_loop->return_value = 0;
	if (g_pid_loop->bang == 1)
		g_pid_loop->bang = 0;
	return (0);
}

int			exec_if(t_ast *ast)
{
	t_ast *tmp;

	tmp = ast->first_son->brother;
	type_node(ast->first_son);
	if (ast->first_son->brother)
	{
		if (g_pid_loop->return_value == 0 && g_pid_loop->bang == 0)
		{
			type_node(ast->first_son->brother);
			return (g_pid_loop->return_value);
		}
		else
			go_loop(ast, tmp);
	}
	g_pid_loop->return_value = 0;
	return (g_pid_loop->return_value);
}
