/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_separators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 00:13:26 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 00:14:53 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			is_newline(int c)
{
	return (c == '\n');
}

int			is_whitespace(int c)
{
	return (c == ' ' || c == '\t');
}

void		discard_whitespace(char *input, int *index)
{
	while (input[(*index) + 1] && is_whitespace(input[(*index) + 1]))
		++(*index);
}

void		discard_comment(char *input, int *index)
{
	while (input[(*index) + 1] && !is_newline(input[(*index) + 1]))
		++(*index);
}
