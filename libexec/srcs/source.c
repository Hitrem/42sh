/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 23:27:24 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 04:43:52 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "source.h"
#include "parser.h"
#include "local_var.h"
#include "readline.h"

int		parse_source(char *path)
{
	t_ast	*tree;
	char	*buff;

	tree = NULL;
	buff = NULL;
	buff = readfile(path, 1);
	if (buff != NULL)
	{
		tree = get_ast(buff);
		init_var_function(tree);
		free_lists();
	}
	free(buff);
	return (0);
}

int		my_source(t_ast *node)
{
	char	*file_path;

	file_path = NULL;
	if (node->brother == NULL)
		file_path = "~/.42shrc";
	else
		file_path = node->brother->token->token;
	return (parse_source(file_path));
}
