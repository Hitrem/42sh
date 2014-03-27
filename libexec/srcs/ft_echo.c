/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:33:37 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 06:16:36 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void		ft_token(t_ast *tmp, t_echo *ech)
{
	int	j;

	j = 1;
	while (tmp->token->token[j])
	{
		if (tmp->token->token[j] != 'n' && tmp->token->token[j] != 'e'
				&& tmp->token->token[j] != 'E')
			ech->opt = 0;
		j++;
	}
	if (ech->opt == 1)
	{
		++ech->num_opt;
		block_of_options(ech, tmp);
	}
}

t_echo			*get_options(t_ast *node, t_echo *ech)
{
	t_ast		*tmp;

	ech->n = 0;
	ech->e = 0;
	tmp = node->brother;
	ech->opt = 1;
	while (ech->opt == 1 && tmp)
	{
		if (tmp->token->token[0] == '-' && tmp->token->token[1])
			ft_token(tmp, ech);
		else
			ech->opt = 0;
		tmp = tmp->brother;
	}
	return (ech);
}

static int		change_return_value(t_echo *ech, t_ast *node)
{
	free(ech->cmd);
	free(ech);
	node->return_value = 0;
	g_pid_loop->return_value = 0;
	if (g_pid_loop->bang == 1)
	{
		g_pid_loop->bang = 0;
		if (g_pid_loop->return_value == 0)
			g_pid_loop->return_value = 1;
		else if (g_pid_loop->return_value != -1)
			g_pid_loop->return_value = 0;
	}
	return (g_pid_loop->return_value);
}

static void		check_echo(t_echo *ech)
{
	if (ech->cmd == NULL)
	{
		if (ech->n == 0)
			write(1, "\n", 1);
	}
	else
	{
		if (ech->n == 0)
			write_simple_echo(ech);
		else
			write(1, ech->cmd, strlen(ech->cmd));
	}
}

int				ft_echo(t_ast *node)
{
	t_echo	*ech;
	t_ast	*tmp;
	int		num;
	int		val;

	ech = init_echo(node);
	num = 0;
	tmp = node->brother;
	while (num != ech->num_opt)
	{
		tmp = tmp->brother;
		num++;
	}
	val = 512;
	ech->cmd = build_cmd(tmp, val, ech);
	check_echo(ech);
	return (change_return_value(ech, node));
}
