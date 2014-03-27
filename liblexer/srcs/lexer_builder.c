/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 00:15:52 by pferry            #+#    #+#             */
/*   Updated: 2014/03/27 10:26:15 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "my_string.h"
#include "global.h"
#include "lexer_functions.h"
#include "lexer.h"

char			*my_string_builder(char *dst, char new)
{
	int len;

	len = strlen(dst);
	if (!dst)
	{
		dst = malloc(sizeof(char) * 2);
		dst[0] = new;
		dst[1] = '\0';
		return (dst);
	}
	dst = realloc(dst, sizeof(char) * (len + 2));
	dst[len] = new;
	dst[len + 1] = '\0';
	return (dst);
}

static void		ft_func1(t_token *out, char *input, int *index, int choice)
{
	if (choice)
	{
		free(out->token);
		out->token = build_exp_delim(input, index, '(', ')');
	}
	else
	{
		free(out->token);
		out->token = build_exp_delim(input, index, '{', '}');
	}
}

t_token			*build_expansion(char *input, int *index)
{
	t_token		*out;

	out = init_token(VARIABLE, NULL);
	++(*index);
	if (input[*index])
	{
		if (input[*index] == '(')
			ft_func1(out, input, index, 1);
		else if (input[*index] == '{')
			ft_func1(out, input, index, 0);
		else
		{
			while (input[(*index) + 1] && !is_delimiter(input[(*index) + 1]))
				build_token(out, input[(*index)++]);
			build_token(out, input[(*index)]);
		}
		return (out);
	}
	free_token(out);
	return (NULL);
}
