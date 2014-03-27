/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shopt_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:54:08 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 06:09:56 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "shopt.h"
#include "readline.h"

int			find_optname(char *optname, t_shpt *g_shpt)
{
	if (g_shpt == NULL)
	{
		g_pid_loop->return_value = 2;
		return (2);
	}
	if (strcmp(optname, g_shpt->name) == 0)
	{
		if (strcmp(g_shpt->on_off, "off") == 0)
		{
			g_pid_loop->return_value = 1;
			return (1);
		}
		else
		{
			g_pid_loop->return_value = 0;
			return (0);
		}
	}
	return (find_optname(optname, g_shpt->next));
}

static void	find_name(int i, t_ast *tmp, int ok)
{
	if (i == 1 && ok == 0)
	{
		if (tmp->brother
				&& (find_optname(tmp->brother->token->token, g_shpt) == 2
				|| find_optname(tmp->brother->token->token, g_shpt) == 1))
		{
			g_pid_loop->return_value = 1;
			ok = 1;
		}
	}
	if (i == 2 && ok == 0)
	{
		if (find_optname(tmp->token->token, g_shpt) == 2
				|| find_optname(tmp->token->token, g_shpt) == 1)
		{
			g_pid_loop->return_value = 1;
			ok = 1;
		}
	}
	tmp = tmp->brother;
}

int			check_return_value(t_ast *node, int i)
{
	int			ok;
	t_ast		*tmp;

	ok = 0;
	tmp = node;
	while (tmp && ok == 0)
		find_name(i, tmp, ok);
	return (g_pid_loop->return_value);
}

static int	is_used(t_ast *tmp, unsigned int i, char *set, int var)
{
	if (tmp->token->token[0] == '-' && var &&
		(((strcmp(set, "-u") == 0 && tmp->token->token[i] != 's'))
			|| (strcmp(set, "-s") == 0 && tmp->token->token[i] != 'u')))
	{
		g_pid_loop->return_value = error_message_usage(tmp, i);
		return (1);
	}
	if (tmp->token->token[0] != '-')
		var = 2;
	i++;
	tmp = tmp->brother;
	return (0);
}

int			check_option_used(t_ast *node, char *set)
{
	int					var;
	t_ast				*tmp;
	unsigned int		i;

	tmp = node;
	var = 0;
	while (tmp)
	{
		if (strcmp(tmp->token->token, set) == 0)
		{
			write(2, "42sh: shopt: cannot set ", 24);
			write(2, "and unset shell options simultaneously\n", 39);
			node->return_value = 1;
			g_pid_loop->return_value = 1;
			return (1);
		}
		i = 1;
		while (i < strlen(tmp->token->token))
			is_used(tmp, i, set, var);
		tmp = tmp->brother;
	}
	return (var);
}
