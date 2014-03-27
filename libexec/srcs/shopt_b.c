/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shopt_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:50:51 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 06:10:37 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "shopt.h"
#include "readline.h"

void		valid_or_not_valid(t_ast *tmp)
{
	if (tmp->brother
			&& find_optname(tmp->brother->token->token, g_shpt) != 2)
		print_valid(tmp);
	else if (tmp->brother)
		print_invalid(tmp, 2);
}

static int	ft_zero(void)
{
	g_pid_loop->return_value = 0;
	return (0);
}

int			option_q(t_ast *node)
{
	t_ast	*tmp;

	if (node == NULL)
		ft_zero();
	tmp = node;
	while (tmp)
	{
		if (find_optname(tmp->token->token, g_shpt) == 0)
			tmp = tmp->brother;
		else if (find_optname(tmp->token->token, g_shpt) == 1)
		{
			g_pid_loop->return_value = 1;
			return (1);
		}
		else if (find_optname(tmp->token->token, g_shpt) == 2)
		{
			print_invalid_argument(tmp);
			g_pid_loop->return_value = 1;
			return (1);
		}
	}
	g_pid_loop->return_value = 0;
	return (0);
}

void		option_off(t_shpt *g_shpt, t_ast *node)
{
	int		check;

	if (g_shpt == NULL)
		return ;
	check = check_option_used(node, "-s");
	if (check == 1)
		return ;
	else if (check == 2)
		change_var(node, g_shpt, 2);
	else
	{
		if (strcmp(g_shpt->on_off, "off") == 0)
		{
			write(1, g_shpt->name, strlen(g_shpt->name));
			if (strlen(g_shpt->name) < 8)
				write(1, "\t", 1);
			write(1, "\t", 1);
			write(1, g_shpt->on_off, strlen(g_shpt->on_off));
			write(1, "\n", 1);
			g_pid_loop->return_value = 0;
		}
		option_off(g_shpt->next, node);
	}
}

void		option_on(t_shpt *g_shpt, t_ast *node)
{
	int		check;

	if (g_shpt == NULL)
		return ;
	check = check_option_used(node, "-u");
	if (check == 1)
		return ;
	else if (check == 2)
		change_var(node, g_shpt, 1);
	else
	{
		if (strcmp(g_shpt->on_off, "on") == 0)
		{
			write(1, g_shpt->name, strlen(g_shpt->name));
			if (strlen(g_shpt->name) < 8)
				write(1, "\t", 1);
			write(1, "\t", 1);
			write(1, g_shpt->on_off, strlen(g_shpt->on_off));
			write(1, "\n", 1);
			g_pid_loop->return_value = 0;
		}
		option_on(g_shpt->next, node);
	}
}
