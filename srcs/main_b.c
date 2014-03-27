/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 12:26:35 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 12:35:48 by jwoodrow         ###   ########.fr       */
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

void			ft_loop(t_ast **tree, int *ret, char **argv, t_shpt *g_shpt)
{
	char		*commands;

	commands = NULL;
	readline(&commands, argv[1], '\n');
	*tree = get_ast(commands);
	if (strcmp(g_shpt->on_off, "on") == 0)
		ast_printer(*tree, "tree.dot");
	*ret = init_var_function(*tree);
	free_all();
	free(commands);
}
