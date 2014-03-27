/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tokenizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 00:09:20 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 10:44:33 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "lexer_functions.h"
#include "lexer.h"

static void			ft_func1(t_token **exp, char *input, int *index,
t_list **list)
{
	*exp = build_expansion(input, index);
	append_and_reset(list, *exp);
	free(*exp);
}

void				rule_34(t_token *cur_tok, t_list **list, char *input,
int *index)
{
	char		cur;
	t_token		*exp;

	cur = input[*index];
	if (is_start_of_expansion(cur))
	{
		ft_func1(&exp, input, index, list);
		add_newline(cur_tok, list, input, index);
	}
	else if (is_operator(cur))
	{
		if (cur_tok->token)
		{
			if (is_number(cur_tok->token) && (cur == '>' || cur == '<'))
				cur_tok->type = IO_NUMBER;
			else if (cur == '{' || cur == '}')
			{
				build_token(cur_tok, cur);
				return ;
			}
			append_and_reset(list, cur_tok);
		}
		cur_tok->type = (cur == '=') ? ASSIGNMENT : OPERATOR;
		build_token(cur_tok, cur);
	}
}

void				rule_56(t_token *cur_tok, t_list **list, char *input,
int *index)
{
	char		cur;

	cur = input[*index];
	add_newline(cur_tok, list, input, index);
	if (is_whitespace(cur) && cur_tok->token)
	{
		append_and_reset(list, cur_tok);
		discard_whitespace(input, index);
		cur_tok->preceded_by_whitespace = 1;
	}
}

t_list				*get_tokens(char *input)
{
	t_list		*list;
	t_token		*cur_tok;

	list = NULL;
	if (!input)
		return (NULL);
	cur_tok = init_token(WORD, NULL);
	loop(&list, &cur_tok, input);
	if (cur_tok->token)
	{
		if (!list)
			list = list_init(1, get_token_copy(cur_tok));
		else
			list_append(list, get_token_copy(cur_tok));
	}
	free_token(cur_tok);
	correct_token_types(list);
	return (list);
}
