/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_recognition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 00:14:59 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 11:10:08 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <ctype.h>
#include "my_string.h"
#include "list.h"
#include "lexer_functions.h"
#include "lexer.h"

static const char	*g_reserved_words[] = {
	"!", "{", "}", "case", "do", "done", "elif", "else", "esac", "fi", "for",
	"if", "in", "then", "until", "while", "function", '\0'
};

int				is_reserved_word(char *token)
{
	int			i;

	i = 0;
	while (g_reserved_words[i])
	{
		if (!strcmp(g_reserved_words[i], token))
			return (1);
		i++;
	}
	return (0);
}

static int		change_to_reserved(t_token *p_prev, t_token *prev, \
t_token *current)
{
	return ((is_command_delimiter(prev))
	|| (is_reserved_word(prev->token) && strcmp(current->token, "case")
	&& strcmp(current->token, "for") && strcmp(current->token, "in"))
	|| (p_prev && p_prev->type == FOR));
}

static int		change_assignment(t_token *current)
{
	char		*tok;
	int			i;

	i = 1;
	tok = current->token;
	if (tok[0] != '=' && !isdigit(tok[0]) && (isalpha(tok[0]) || tok[0] == '_')
	&& strstr(tok, "="))
	{
		while (tok[i] != '=')
		{
			if (!(isdigit(tok[i]) || isalpha(tok[i]) || tok[i] == '_'))
				break ;
			i++;
		}
	}
	return (tok[i] == '=');
}

static void		ft_func1(t_list **tmp, t_token **prev, t_token **p_prev,
t_list *list)
{
	*tmp = list;
	*prev = NULL;
	*p_prev = NULL;
}

void			correct_token_types(t_list *list)
{
	t_list			*tmp;
	t_token			*prev;
	t_token			*p_prev;
	t_token			*current;

	ft_func1(&tmp, &prev, &p_prev, list);
	while (tmp)
	{
		current = tmp->value;
		if (!current)
			break ;
		if (!current->quoted)
		{
			if (is_reserved_word(current->token) &&
					change_to_reserved(p_prev, prev, current))
				current->type = get_reserved_type(current->token);
			else if (change_assignment(current))
				current->type = ASSIGNMENT_WORD;
			else if (current->type == OPERATOR || current->type == REDIRECTION)
				current->type = get_separator_type(current->token);
		}
		p_prev = prev;
		prev = current;
		tmp = tmp->next;
	}
}
