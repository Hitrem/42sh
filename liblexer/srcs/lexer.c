/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 00:03:36 by pferry            #+#    #+#             */
/*   Updated: 2014/03/27 04:36:43 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "lexer_functions.h"
#include "lexer.h"

t_token		*init_token(t_type type, char *token)
{
	t_token		*new;

	new = calloc(1, sizeof(t_token));
	new->type = type;
	new->token = token ? strdup(token) : NULL;
	new->line = -1;
	new->preceded_by_whitespace = 0;
	return (new);
}

t_token		*get_token_copy(t_token *tok)
{
	t_token		*new;

	new = calloc(1, sizeof(t_token));
	new->type = tok->type;
	new->token = strdup(tok->token);
	new->line = tok->line;
	new->quoted = tok->quoted;
	new->preceded_by_whitespace = tok->preceded_by_whitespace;
	return (new);
}

void		append_and_reset(t_list **list, t_token *cur_tok)
{
	t_token		*new;

	new = get_token_copy(cur_tok);
	*list = list_append(*list, new);
	cur_tok->type = WORD;
	free(cur_tok->token);
	cur_tok->token = NULL;
	cur_tok->preceded_by_whitespace = 0;
	cur_tok->quoted = 0;
}

int			are_complementary(char *input, int index)
{
	char cur;
	char prev;

	cur = input[index];
	prev = input[index - 1];
	if (!index)
		return (1);
	return ((prev == '>' && cur == '>')
	|| (prev == '<' && cur == '<')
	|| (prev == '>' && cur == '&')
	|| (prev == '<' && cur == '&')
	|| (prev == '>' && cur == '|')
	|| (prev == '<' && cur == '>')
	|| (prev == '&' && cur == '&')
	|| (prev == '|' && cur == '|')
	|| (prev == '(' && cur == ')'));
}

void		free_token(t_token *token)
{
	if (token)
	{
		free(token->token);
		free(token);
	}
}
