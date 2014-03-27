/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shopt_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 23:24:49 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 02:54:29 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "shopt.h"
#include "readline.h"

void print_shopt(t_shpt *g_shpt)
{
	if (g_shpt == NULL)
		return ;
	write(1, g_shpt->name, strlen(g_shpt->name));
	if (strlen(g_shpt->name) < 8)
		write(1, "\t", 1);
	write(1, "\t", 1);
	write(1, g_shpt->on_off, strlen(g_shpt->on_off));
	write(1, "\n", 1);
	print_shopt(g_shpt->next);
	g_pid_loop->return_value = 0;
}

void print_valid(t_ast *node)
{
	t_shpt *tmp;

	tmp = g_shpt;
	while (tmp)
	{
		if (strcmp(node->brother->token->token, tmp->name) == 0)
			break ;
		tmp = tmp->next;
	}
	write(1, tmp->name, strlen(tmp->name));
	if (strlen(g_shpt->name) < 8)
		write(1, "\t", 1);
	write(1, "\t", 1);
	write(1, tmp->on_off, strlen(tmp->on_off));
	write(1, "\n", 1);
	node->return_value = 0;
	if (strcmp(tmp->on_off, "off") == 0)
		g_pid_loop->return_value = 1;
}

void print_invalid(t_ast *node, int i)
{
	if (i == 1)
	{
		write(2, "42sh: shopt: ", 13);
		write(2, node->brother->token->token,
				strlen(node->brother->token->token));
		write(2, ": invalid option\nshopt: usage: shopt [-qsu] [optname ...]\n",
				58);
		node->return_value = 2;
		g_pid_loop->return_value = 2;
	}
	else if (i == 2)
	{
		write(2, "42sh: shopt: ", 13);
		write(2, node->brother->token->token,
				strlen(node->brother->token->token));
		write(2, ": invalid shell option name\n", 28);
		node->return_value = 1;
		g_pid_loop->return_value = 1;
	}
}

void print_invalid_argument(t_ast *tmp)
{
	write(2, "42sh: shopt: ", 13);
	write(2, tmp->token->token, strlen(tmp->token->token));
	write(2, ": invalid shell option name\n", 28);
}

void print_o_positive(t_shpt *g_shpt)
{
	if (g_shpt == NULL)
		return ;
	write(1, "shopt ", 7);
	if (strcmp(g_shpt->on_off, "on") == 0)
		write(1, "-s ", 3);
	else
		write(1, "-u ", 3);
	write(1, g_shpt->name, strlen(g_shpt->name));
	write(1, "\n", 1);
	g_pid_loop->return_value = 0;
	print_o_positive(g_shpt->next);
}
