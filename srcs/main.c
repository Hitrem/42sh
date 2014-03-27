/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 01:58:01 by sde-segu          #+#    #+#             */
/*   Updated: 2014/03/27 12:35:41 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "check_options.h"
#include "prompts.h"
#include "readline.h"
#include "my_string.h"
#include "parser.h"
#include "parser_functions.h"
#include "exec.h"
#include "shopt.h"
#include "main.h"

t_var			*g_var;
t_funct			*g_funct;
t_aliases		*g_alias;
t_pid_loop		*g_pid_loop;
t_shpt			*g_shpt;

void			free_all(void)
{
	free_funct();
	free_lists();
	free_fun_lists();
	free_alias();
	free_variables();
	free_shopt();
	free(g_pid_loop);
}

static int		ps2_option_c(char *argv[])
{
	t_ast	*tree;
	int		ret;
	char	*commands;

	g_pid_loop->is_in_loop = 0;
	commands = argv[2];
	tree = get_ast(commands);
	if (strcmp(g_shpt->on_off, "on") == 0)
		ast_printer(tree, "tree.dot");
	ret = init_var_function(tree);
	free_all();
	return (ret);
}

static void		init_g_pid_loop(void)
{
	g_pid_loop = NULL;
	g_pid_loop = malloc(sizeof(t_pid_loop));
	g_pid_loop->return_value = -1;
	g_pid_loop->is_in_file = 0;
	g_shpt = init_shopt();
	g_funct = NULL;
	g_alias = NULL;
	setenv("SHELL", "42sh", 1);
}

static t_var	*set_g_var(int argc, char *argv[])
{
	char *prompt_name;
	char *prompt_init;

	prompt_name = NULL;
	prompt_name = my_strcpy("PS1");
	prompt_init = NULL;
	prompt_init = my_strcpy("42sh$ ");
	g_var = init_var(argc, argv);
	g_var = add_var(prompt_name, prompt_init, g_var);
	return (g_var);
}

int				main(int argc, char **argv)
{
	int		l;
	int		ret;
	t_ast	*tree;

	init_g_pid_loop();
	l = check_opt(argc, argv);
	g_var = set_g_var(argc, argv);
	ret = 0;
	if (!l)
		return (0);
	else if (l == -2)
		return (2);
	else if (l == -1)
	{
		g_pid_loop->is_in_file = 1;
		ft_loop(&tree, &ret, argv, g_shpt);
	}
	else if (l == -3)
		return (ps1_loop());
	else
		return (ps2_option_c(argv));
	return (ret);
}
