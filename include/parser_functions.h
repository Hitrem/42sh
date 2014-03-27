/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:38:19 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 12:39:31 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_FUNCTIONS_H
# define PARSER_FUNCTIONS_H

# include "parser.h"

typedef struct			s_lists
{
	t_list				*tokens;
	t_list				*garbage_tokens;
	t_list				*garbage_fun_tokens;
	t_list				*garbage_nodes;
	t_list				*garbage_fun_nodes;
}						t_lists;
extern t_lists			*g_lists;
int						and_or(t_ast **ast);
int						is_redirection(t_type type);
int						simple_command(t_ast **ast);
int						command(t_ast **ast);
int						rule_if(t_ast **ast);
int						compound_list(t_ast **ast);
int						rule_while_until(t_ast **ast);
int						rule_for(t_ast **ast);
int						print_and_exit(char *message);
t_ast					*get_new_son(t_ast **ast, t_type type, char *token);
void					discard_newline(void);
void					add_tok_garbage(t_token *tok);
int						add_bang(t_ast **ast, t_lists *g_lists);
int						pipeline(t_ast **ast, t_lists *g_lists);
int						ft_func(t_ast **ast, t_lists *g_lists,
t_token **current);
int						is_shell_command(t_token *tok);
int						is_funcdec(t_token *tok, t_token *next);
void					element(t_ast **ast);
int						handle_loops(t_ast **ast);
int						shell_command(t_ast **ast);
int						funcdec(t_ast **ast);
void					in_absent(t_ast **ast);
int						in_present(t_ast **ast);
int						handle_in(t_ast **ast);
int						for_loop(t_ast **ast);
int						discard_to_done(void);

#endif
