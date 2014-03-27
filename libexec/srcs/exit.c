/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:21:33 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 02:40:04 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "prompts.h"
#include "readline.h"
#include "function.h"

static int		no_argument(void)
{
	if (g_pid_loop->is_in_loop == 1)
		printf("exit\n");
	free_funct();
	free_lists();
	free_fun_lists();
	free_alias();
	free_variables();
	free_shopt();
	free_prog(NULL, NULL, g_pid_loop->is_in_loop);
	exit(0);
}

static int		too_much_arguments(t_ast *node)
{
	if (g_pid_loop->is_in_loop == 1)
		printf("exit\n");
	write(2, "42sh: exit: too many arguments\n", 31);
	node->return_value = 1;
	g_pid_loop->return_value = 1;
	return (g_pid_loop->return_value);
}

static int		letter(t_ast *node)
{
	if (g_pid_loop->is_in_loop == 1)
		printf("exit\n");
	write(2, "42sh: exit: ", 12);
	write(2, node->brother->token->token,
			my_strlen(node->token->token));
	write(2, ": numeric argument required\n", 28);
	free_funct();
	free_lists();
	free_alias();
	free_variables();
	free_shopt();
	free_fun_lists();
	free_prog(NULL, NULL, g_pid_loop->is_in_loop);
	exit(255);
}

static void		node_bro(t_ast *node, int j)
{
	if ((node->brother->token->token[j] < '0'
				|| node->brother->token->token[j] > '9')
			&& node->brother->token->token[0] != '-')
		letter(node);
	j++;
}

int				my_exit(t_ast *node)
{
	int			j;
	int			ret;

	if (node->brother == NULL)
		no_argument();
	j = 0;
	while (node->brother->token->token[j])
		node_bro(node, j);
	if (node->brother->brother != NULL)
		return (too_much_arguments(node));
	if (g_pid_loop->is_in_loop == 1)
		printf("exit\n");
	ret = atoi(node->brother->token->token);
	free_funct();
	free_lists();
	free_alias();
	free_variables();
	free_shopt();
	free_fun_lists();
	free_prog(NULL, NULL, g_pid_loop->is_in_loop);
	exit(ret);
}
