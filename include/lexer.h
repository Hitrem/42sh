/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:19:36 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 12:39:48 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "list.h"

typedef enum		e_type
{
	COMMANDS,
	COMMAND,
	FUNCTION,
	VARIABLE,
	ASSIGNMENT,
	IF,
	WHILE,
	UNTIL,
	FOR,
	CASE,
	AND_IF,
	OR_IF,
	RREDIR,
	LREDIR,
	DGREAT,
	DLESS,
	DLESSDASH,
	GREATAND,
	LESSAND,
	CLOBBER,
	LESSGREAT,
	PIPE,
	BANG,
	OPERATOR,
	REDIRECTION,
	ASSIGNMENT_WORD,
	WORD,
	IO_NUMBER,
	HEREDOC,
	NEWLINE,
	SEMICOLON,
	LBRACE,
	RBRACE,
	DOUBLEPARENT,
	LPARENT,
	RPARENT,
	THEN,
	ELIF,
	ELSE,
	FI,
	DO,
	DONE,
	IN,
	EMPTY,
}					t_type;

typedef struct		s_token
{
	t_type			type;
	int				quoted;
	int				line;
	int				preceded_by_whitespace;
	char			*token;
}					t_token;
t_token				*init_token(t_type type, char *token);
t_token				*get_token_copy(t_token *tok);
void				append_and_reset(t_list **list, t_token *cur_tok);
int					are_complementary(char *input, int index);
void				free_token(t_token *token);
t_list				*get_tokens(char *input);
void				print_tokens(t_list *tmp);

char				*my_string_builder(char *dst, char new);
int					is_delimiter(char c);
char				*build_exp_delim(char *input, int *index
	, char delim, char ndelim);

#endif
