/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:26:13 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 11:06:42 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_FUNCTIONS_H
# define LEXER_FUNCTIONS_H

# include "lexer.h"
int			is_number(char *s);
int			is_operator(int c);
int			is_quoting(int c);
int			is_word(int c);
int			is_start_of_expansion(int c);
int			is_newline(int c);
int			is_whitespace(int c);
void		discard_whitespace(char *input, int *index);
void		discard_comment(char *input, int *index);
void		build_token(t_token *tok, char cur);
t_token		*build_expansion(char *input, int *index);
void		correct_token_types(t_list *list);
void		handle_quoting(t_token *cur_tok, t_list **list, char *input,
int *index);
void		handle_backslash(t_token *cur_tok, char *input, int *index);
int			backslash_is_quoted(t_token *cur_tok, char *input, int index);
void		add_newline(t_token *cur_tok, t_list **l, char *input,
int *index);
void		rule_1(t_token *cur_tok, t_list **list, char *input,
int *index);
void		loop(t_list **list, t_token **cur_tok, char *input);
void		rule_34(t_token *cur_tok, t_list **list, char *input,
int *index);
void		rule_56(t_token *cur_tok, t_list **list, char *input,
int *index);
int			is_reserved_word(char *token);
t_type		get_reserved_type2(char *token);
t_type		get_reserved_type(char *token);
t_type		get_redirection_type(char *token);
t_type		get_separator_type(char *token);
int			is_command_delimiter(t_token *tok);
int			is_command_delimiter(t_token *tok);

#endif
