/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 18:56:41 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 03:13:27 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "parser_functions.h"
#include "parser.h"

static char		*get_color(t_ast *tmp)
{
	t_type		type;

	if (tmp)
	{
		type = tmp->token->type;
		if (type == COMMANDS)
			return ("brown1");
		else if (type == COMMAND)
			return ("cornflowerblue");
		else if (type == FUNCTION)
			return ("gold2");
		else if (type == IF || type == WHILE || type == UNTIL || type == FOR ||
				type == IN)
			return ("forestgreen");
		else if (is_redirection(type) || type == PIPE || type == VARIABLE)
			return ("tan2");
	}
	return ("");
}

static void		print_relations(FILE *out, t_ast *ast, int father_index)
{
	static int			tmp_index;
	t_ast				*tmp;
	char				*color;

	if (ast)
	{
		tmp_index = 0;
		tmp = ast->first_son;
		color = "";
		while (tmp)
		{
			++tmp_index;
			color = get_color(tmp);
			if (!strcmp(color, ""))
				fprintf(out, "%d [label=\"%s\"];\n",
						tmp_index, tmp->token->token);
			else
				fprintf(out, "%d [label=\"%s\", style=filled, color=%s];\n",
						tmp_index, tmp->token->token, color);
			fprintf(out, "%d -- %d;\n", father_index, tmp_index);
			print_relations(out, tmp, tmp_index);
			tmp = tmp->brother;
		}
	}
}

void			ast_printer(t_ast *ast, char *filename)
{
	FILE			*f;

	if (!ast)
		return ;
	f = fopen(filename, "w");
	if (!f)
		return ;
	fprintf(f, "graph example {\n");
	fprintf(f, "0 [label=\"%s\", style=filled, color=brown1];\n",
			ast->token->token);
	print_relations(f, ast, 0);
	fprintf(f, "}\n");
	fclose(f);
}
