/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 00:51:26 by sde-segu          #+#    #+#             */
/*   Updated: 2014/03/27 06:15:00 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "prompts.h"
#include "local_var.h"
#include "readline.h"
#include "history.h"
#include "parser.h"
#include "exec.h"
#include "source.h"

static int		exec_buff(char *buff, t_ast *tree)
{
	int ret2;

	tree = get_ast(buff);
	//
	if (strcmp(g_shpt->on_off, "on") == 0)
		ast_printer(tree, "tree.dot");
	ret2 = init_var_function(tree);
	return (ret2);
}

void			resource_parser(void)
{
	char *home;

	home = NULL;
	home = malloc(sizeof(char) * 128);
	home = getenv("HOME");
	//
	home = strcat(home, "/.42shrc");
	parse_source("/etc/42shrc");
	parse_source(home);
	free(home);
}

static void		loop(char **buff, t_ast **tree, int *ret)
{
	char *prompt;
	char *tmp;

	while (1)
	{
		if (g_pid_loop->is_in_loop)
		{
			prompt = reload_prompt(find_var("PS1", g_var));
			//
			printf("%s", prompt);
			free(prompt);
		}
		fflush(NULL);
		if (!readline2(buff, NULL, '\n') && !g_pid_loop->is_in_loop)
			break ;
		add_line_history(g_current_cmd->last, 0);
		tmp = check_var(g_current_cmd->last);
		if (!strcmp(tmp, ""))
			*ret = exec_buff(g_current_cmd->last, *tree);
		else
			free(tmp);
		free_lists();
	}
}

int				ps1_loop(void)
{
	char	*buff;
	t_ast	*tree;
	int		ret;

	buff = NULL;
	ret = 0;
	tree = NULL;
	init_prompt();
	loop(&buff, &tree, &ret);
	free_funct();
	free_lists();
	free_fun_lists();
	free_alias();
	free_variables();
	free_shopt();
	free_prog(buff, tree, g_pid_loop->is_in_loop);
	return (ret);
}
