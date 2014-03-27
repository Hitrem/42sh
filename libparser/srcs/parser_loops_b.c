/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_loops_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 09:34:03 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 09:50:48 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser_functions.h"
#include "parser.h"

void			in_absent(t_ast **ast)
{
	t_ast	*new_in;
	t_token	*new_in_tok;

	new_in = get_new_son(ast, IN, "IN");
	new_in_tok = init_token(VARIABLE, "$@");
	add_son(new_in, init_node(new_in_tok, NULL, NULL));
	add_tok_garbage(new_in_tok);
}

static int		ft_func1(t_token **next, t_ast **new_in, int *once, t_ast **ast)
{
	if (!g_lists->tokens->next)
		return (print_and_exit("Unexpected end of file"));
	*next = g_lists->tokens->next->value;
	if ((*next)->type != WORD && (*next)->type != VARIABLE)
		return (discard_to_done());
	*new_in = get_new_son(ast, IN, "IN");
	*once = 1;
	return (-1337);
}

int				in_present(t_ast **ast)
{
	t_token	*current;
	t_token	*next;
	t_ast	*new_in;
	int		once;
	int		ret;

	current = g_lists->tokens->value;
	if (current->type == IN)
	{
		if ((ret = ft_func1(&next, &new_in, &once, ast)) != 1337)
			return (ret);
		while (once || g_lists->tokens)
		{
			once = 0;
			if (!(g_lists->tokens = g_lists->tokens->next))
				return (print_and_exit("Unexpected end of file"));
			current = g_lists->tokens->value;
			if (current->type != WORD && current->type != VARIABLE)
				break ;
			add_son(new_in, init_node(current, NULL, NULL));
		}
	}
	else
		in_absent(ast);
	return (1);
}

int				handle_in(t_ast **ast)
{
	t_token	*current;

	current = g_lists->tokens->value;
	if (current->type != WORD)
		return (print_and_exit("Expected WORD token"));
	add_son(*ast, init_node(current, NULL, NULL));
	g_lists->tokens = g_lists->tokens->next;
	discard_newline();
	if (!g_lists->tokens)
		return (print_and_exit("Unexpected end of file"));
	current = g_lists->tokens->value;
	return (in_present(ast));
}

int				for_loop(t_ast **ast)
{
	t_token	*current;
	t_ast	*new_do;

	current = g_lists->tokens->value;
	if (current->type != DO)
		return (print_and_exit("Missing 'do' keyword in loop statement"));
	g_lists->tokens = g_lists->tokens->next;
	new_do = get_new_son(ast, COMMANDS, "COMMANDS");
	if (!compound_list(&new_do))
		return (0);
	if (!g_lists->tokens)
		return (print_and_exit("Unexpected end of file"));
	current = g_lists->tokens->value;
	if (current->type != DONE)
		return (print_and_exit("Expected 'done' at the end of loop statement"));
	g_lists->tokens = g_lists->tokens->next;
	return (1);
}
