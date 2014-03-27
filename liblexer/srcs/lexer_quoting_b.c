/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quoting_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 06:28:03 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 10:25:24 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "lexer_functions.h"

static void		ft_func1(t_token *cur_tok, char cur, int *index)
{
	if (cur == '\n')
		++(*index);
	else if (cur == '\"')
		cur_tok->quoted = 4;
	else if (cur == '\'')
		cur_tok->quoted = 5;
	else
		build_token(cur_tok, cur);
	if (!cur_tok->quoted)
		cur_tok->quoted = 1;
}

void			handle_backslash(t_token *cur_tok, char *input, int *index)
{
	char	cur;
	char	count;

	cur = input[*index];
	count = 0;
	if (backslash_is_quoted(cur_tok, input, *index))
	{
		build_token(cur_tok, cur);
		return ;
	}
	while (cur == '\\')
	{
		++count;
		if (!(count % 2))
			build_token(cur_tok, cur);
		cur = input[++(*index)];
	}
	ft_func1(cur_tok, cur, index);
}
