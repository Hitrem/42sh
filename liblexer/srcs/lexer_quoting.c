/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quoting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 00:23:45 by pferry            #+#    #+#             */
/*   Updated: 2014/03/27 06:29:38 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "lexer_functions.h"

int g_prev;

int			backslash_is_quoted(t_token *cur_tok, char *input, int index)
{
	char	next;
	int		quote_lvl;

	next = input[index + 1];
	quote_lvl = cur_tok->quoted;
	if (!(input[index + 1]))
		return (1);
	return (quote_lvl == 3
	|| (quote_lvl == 2 && (next != '$' || next != '\\')));
}

static void	handle_simple(t_token *cur_tok, t_list **list,
		char *input, int *index)
{
	char	cur;

	cur = input[*index];
	if (cur_tok->quoted == 4)
	{
		build_token(cur_tok, cur);
		return ;
	}
	if (cur_tok->quoted == 3)
	{
		append_and_reset(list, cur_tok);
		cur_tok->quoted = g_prev;
		return ;
	}
	g_prev = cur_tok->quoted;
	cur_tok->quoted = 3;
	cur = input[++(*index)];
	while (cur != '\'')
	{
		build_token(cur_tok, cur);
		cur = input[++(*index)];
	}
	append_and_reset(list, cur_tok);
}

void		handle_quoting(t_token *cur_tok, t_list **list, char *input,
		int *index)
{
	char	cur;

	g_prev = 0;
	cur = input[*index];
	if (cur == '\\')
		handle_backslash(cur_tok, input, index);
	else if (cur == '\'')
		handle_simple(cur_tok, list, input, index);
}
