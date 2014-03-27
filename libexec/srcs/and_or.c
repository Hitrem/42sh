/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:21:33 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 02:32:03 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "readline.h"

int and_exec(t_ast *node)
{
	if (g_pid_loop->return_value != 1)
		exec_cmd(node->brother);
	else
	{
		node->brother->return_value = 1;
		g_pid_loop->return_value = 1;
	}
	return (g_pid_loop->return_value);
}

int or_exec(t_ast *node)
{
	if (g_pid_loop->return_value != 0)
		exec_cmd(node->brother);
	else
	{
		node->brother->return_value = 0;
		g_pid_loop->return_value = 0;
	}
	return (g_pid_loop->return_value);
}
