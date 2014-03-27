/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shopt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 22:53:39 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 06:07:49 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "shopt.h"
#include "readline.h"

int				error_message_usage(t_ast *tmp, int i)
{
	char *letter;

	letter = malloc(sizeof(char));
	letter[0] = tmp->token->token[i];
	write(2, "42sh: shopt: -", 14);
	write(2, letter, 1);
	free(letter);
	write(2, ": invalid option\n", 17);
	write(2, "shopt: usage: shopt [-qsu] [optname ...]\n", 41);
	g_pid_loop->return_value = 2;
	return (2);
}

static void		change_sht(t_ast *tmp, int i, t_shpt *g_shpt)
{
	t_shpt	*sht;

	while (tmp)
	{
		if (find_optname(tmp->token->token, g_shpt) != 2)
		{
			sht = g_shpt;
			while (sht)
			{
				if (strcmp(tmp->token->token, sht->name) == 0)
					break ;
				sht = sht->next;
			}
			if (i == 1)
				sht->on_off = "on";
			if (i == 2)
				sht->on_off = "off";
		}
		else
			print_invalid_argument(tmp);
		tmp = tmp->brother;
	}
}

void			change_var(t_ast *node, t_shpt *g_shpt, int i)
{
	t_ast	*tmp;
	t_ast	*ret;

	tmp = node;
	while (tmp->token->token[0] == '-')
		tmp = tmp->brother;
	ret = tmp;
	change_sht(tmp, i, g_shpt);
	g_pid_loop->return_value = check_return_value(ret, 2);
}

static void		option(t_ast *node)
{
	if (node->brother->token->token[1] == 's')
		option_on(g_shpt, node->brother);
	else if (node->brother->token->token[1] == 'u')
		option_off(g_shpt, node->brother);
	else if (node->brother->token->token[1] == 'q')
		option_q(node->brother->brother);
	else
		print_invalid(node, 1);
}

int				my_shopt(t_ast *node)
{
	t_ast		*tmp;

	if (node->brother == NULL)
	{
		print_shopt(g_shpt);
		g_pid_loop->return_value = 0;
		return (0);
	}
	if (node->brother->token->token[0] == '-')
		option(node);
	else
	{
		tmp = node;
		while (tmp)
		{
			valid_or_not_valid(tmp);
			tmp = tmp->brother;
		}
		g_pid_loop->return_value = check_return_value(node, 1);
	}
	return (g_pid_loop->return_value);
}
