/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 01:28:40 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 04:38:38 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "list.h"
#include "lexer.h"

static char		*get_token_string4(int type)
{
	if (type == ELSE)
		return ("ELSE");
	if (type == FI)
		return ("FI");
	if (type == DO)
		return ("DO");
	if (type == DONE)
		return ("DONE");
	if (type == IN)
		return ("IN");
	if (type == FUNCTION)
		return ("FUNCTION");
	if (type == EMPTY)
		return ("EMPTY");
	if (type == ASSIGNMENT)
		return ("ASSIGNMENT");
	if (type == DOUBLEPARENT)
		return ("DOUBLEPARENT");
	if (type == HEREDOC)
		return ("HEREDOC");
	else
		return ("NOT FOUND");
}

static char		*get_token_string3(int type)
{
	if (type == OPERATOR)
		return ("OPERATOR");
	if (type == REDIRECTION)
		return ("REDIRECTION");
	if (type == NEWLINE)
		return ("NEWLINE");
	if (type == SEMICOLON)
		return ("SEMICOLON");
	if (type == LBRACE)
		return ("LBRACE");
	if (type == RBRACE)
		return ("RBRACE");
	if (type == LPARENT)
		return ("LPARENT");
	if (type == RPARENT)
		return ("RPARENT");
	if (type == THEN)
		return ("THEN");
	if (type == ELIF)
		return ("ELIF");
	else
		return (get_token_string4(type));
}

static char		*get_token_string2(int type)
{
	if (type == OR_IF)
		return ("OR_IF");
	if (type == RREDIR)
		return ("RREDIR");
	if (type == LREDIR)
		return ("LREDIR");
	if (type == DGREAT)
		return ("DGREAT");
	if (type == DLESS)
		return ("DLESS");
	if (type == DLESSDASH)
		return ("DLESSDASH");
	if (type == GREATAND)
		return ("GREATAND");
	if (type == LESSAND)
		return ("LESSAND");
	if (type == PIPE)
		return ("PIPE");
	if (type == BANG)
		return ("BANG");
	else
		return (get_token_string3(type));
}

static char		*get_token_string(int type)
{
	if (type == VARIABLE)
		return ("VARIABLE");
	if (type == WORD)
		return ("WORD");
	if (type == ASSIGNMENT_WORD)
		return ("ASSIGNMENT_WORD");
	if (type == IO_NUMBER)
		return ("IO_NUMBER");
	if (type == IF)
		return ("IF");
	if (type == WHILE)
		return ("WHILE");
	if (type == UNTIL)
		return ("UNTIL");
	if (type == FOR)
		return ("FOR");
	if (type == CASE)
		return ("CASE");
	if (type == AND_IF)
		return ("AND_IF");
	else
		return (get_token_string2(type));
}

void			print_tokens(t_list *tmp)
{
	t_token	*current;

	while (tmp)
	{
		current = tmp->value;
		if (!strcmp(current->token, "\n"))
			printf("token: %-10s; type: %-13s; quoted: %d; whitespace: %d\n",
				"\\n", get_token_string(current->type), current->quoted,
				current->preceded_by_whitespace);
		else
			printf("token: %-10s; type: %-13s; quoted: %d; whitespace: %d\n",
				current->token, get_token_string(current->type),
				current->quoted, current->preceded_by_whitespace);
		tmp = tmp->next;
	}
}
