/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_builder_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 06:24:48 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 10:22:10 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "my_string.h"
#include "global.h"
#include "lexer_functions.h"
#include "lexer.h"

int			is_delimiter(char c)
{
	return (is_newline(c) || is_whitespace(c) || c == ';');
}

void		build_token(t_token *tok, char cur)
{
	tok->token = my_string_builder(tok->token, cur);
}

char		*build_exp_delim(char *input, int *index, char delim, char ndelim)
{
	char	*new;
	int		count;

	count = 1;
	new = my_string_builder(NULL, '$');
	new = my_string_builder(new, input[(*index)++]);
	while (count)
	{
		if (!input[*index])
			return (NULL);
		if (input[*index] == delim)
			++count;
		else if (input[*index] == ndelim)
			--count;
		new = my_string_builder(new, input[(*index)]);
		if (count)
			++(*index);
	}
	return (new);
}
