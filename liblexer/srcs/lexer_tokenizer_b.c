/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tokenizer_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 10:27:03 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 10:42:13 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "lexer_functions.h"
#include "lexer.h"

void				rule_1(t_token *cur_tok, t_list **list, char *input, \
int *index)
{
	char		cur;

	cur = input[*index];
	if (is_operator(cur) && are_complementary(input, *index))
		build_token(cur_tok, cur);
	else
	{
		if (cur_tok->type == WORD)
		{
			build_token(cur_tok, cur);
			return ;
		}
		append_and_reset(list, cur_tok);
		if (is_operator(cur))
			cur_tok->type = OPERATOR;
		discard_whitespace(input, index);
		if (!is_whitespace(cur))
			build_token(cur_tok, cur);
		else
			cur_tok->preceded_by_whitespace = 1;
	}
}

void				add_newline(t_token *cur_tok, t_list **l, char *input, \
int *index)
{
	char		cur;

	cur = input[*index];
	if (is_newline(cur))
	{
		if (cur_tok->token)
			append_and_reset(l, cur_tok);
		discard_whitespace(input, index);
		list_append(*l, init_token(NEWLINE, "\n"));
	}
}

static void			ft_init(int *index, char *cur, char *prev, char *input)
{
	*index = 0;
	*cur = input[*index];
	*prev = *cur;
}

void				loop(t_list **list, t_token **cur_tok, char *input)
{
	int			index;
	char		cur;
	char		prev;

	ft_init(&index, &cur, &prev, input);
	while (cur)
	{
		if ((*cur_tok)->token && is_operator(prev) && !is_newline(cur))
			rule_1(*cur_tok, list, input, &index);
		else if (is_quoting(cur))
			handle_quoting(*cur_tok, list, input, &index);
		else if (is_start_of_expansion(cur) || is_operator(cur))
			rule_34(*cur_tok, list, input, &index);
		else if (is_newline(cur) || is_whitespace(cur))
			rule_56(*cur_tok, list, input, &index);
		else if ((*cur_tok)->token && is_word(prev))
			build_token(*cur_tok, cur);
		else if (cur == '#')
			discard_comment(input, &index);
		else
			build_token(*cur_tok, cur);
		prev = cur;
		cur = input[++index];
	}
}
