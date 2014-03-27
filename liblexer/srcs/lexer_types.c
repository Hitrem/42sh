/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 00:08:03 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 00:28:15 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			is_number(char *s)
{
	int			i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int			is_operator(int c)
{
	return (c == '&' || c == '|' || c == ';' || c == '<' || c == '>'
	|| c == '(' || c == ')' || c == '{' || c == '}' || c == '!');
}

int			is_quoting(int c)
{
	return (c == '\\' || c == '\"' || c == '\'');
}

int			is_word(int c)
{
	return (c > 0 && c < 128 && c != is_operator(c));
}

int			is_start_of_expansion(int c)
{
	return (c == '$');
}
