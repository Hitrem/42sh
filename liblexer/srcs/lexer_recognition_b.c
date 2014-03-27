/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_recognition_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 11:00:27 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 11:06:26 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <ctype.h>
#include "my_string.h"
#include "list.h"
#include "lexer.h"

t_type			get_reserved_type2(char *token)
{
	if (!strcmp(token, "do"))
		return (DO);
	if (!strcmp(token, "done"))
		return (DONE);
	if (!strcmp(token, "function"))
		return (FUNCTION);
	return (WORD);
}

t_type			get_reserved_type(char *token)
{
	if (!strcmp(token, "!"))
		return (BANG);
	if (!strcmp(token, "{"))
		return (LBRACE);
	if (!strcmp(token, "}"))
		return (RBRACE);
	if (!strcmp(token, "elif"))
		return (ELIF);
	if (!strcmp(token, "else"))
		return (ELSE);
	if (!strcmp(token, "fi"))
		return (FI);
	if (!strcmp(token, "for"))
		return (FOR);
	if (!strcmp(token, "if"))
		return (IF);
	if (!strcmp(token, "in"))
		return (IN);
	if (!strcmp(token, "then"))
		return (THEN);
	if (!strcmp(token, "until"))
		return (UNTIL);
	if (!strcmp(token, "while"))
		return (WHILE);
	return (get_reserved_type2(token));
}

t_type			get_redirection_type(char *token)
{
	if (!strcmp(token, ">"))
		return (RREDIR);
	if (!strcmp(token, "<"))
		return (LREDIR);
	if (!strcmp(token, ">>"))
		return (DGREAT);
	if (!strcmp(token, "<<"))
		return (DLESS);
	if (!strcmp(token, "<<-"))
		return (DLESSDASH);
	if (!strcmp(token, ">&"))
		return (GREATAND);
	if (!strcmp(token, "<&"))
		return (LESSAND);
	if (!strcmp(token, ">|"))
		return (CLOBBER);
	if (!strcmp(token, "<>"))
		return (LESSGREAT);
	return (EMPTY);
}

t_type			get_separator_type(char *token)
{
	if (!strcmp(token, "&&"))
		return (AND_IF);
	if (!strcmp(token, "|"))
		return (PIPE);
	if (!strcmp(token, "||"))
		return (OR_IF);
	if (!strcmp(token, ";"))
		return (SEMICOLON);
	if (!strcmp(token, "()"))
		return (DOUBLEPARENT);
	if (!strcmp(token, "("))
		return (LPARENT);
	if (!strcmp(token, ")"))
		return (RPARENT);
	return (get_redirection_type(token));
}

int				is_command_delimiter(t_token *tok)
{
	return (!tok || (!tok->quoted && (!strcmp(tok->token, "\n")
	|| !strcmp(tok->token, "()")
	|| !strcmp(tok->token, "{")
	|| !strcmp(tok->token, "fi")
	|| !strcmp(tok->token, ";"))));
}
