/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:35:32 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 02:37:45 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"

typedef struct s_ast		t_ast;
struct						s_ast
{
	t_token					*token;
	int						return_value;
	t_ast					*brother;
	t_ast					*first_son;
};
t_ast						*get_ast(char *input);
t_ast						*init_node(t_token *token, t_ast *brother,
t_ast *first_son);
t_ast						*add_to_sons(t_ast *ast, int nb_of_sons,
t_ast *son, ...);
t_ast						*add_son(t_ast *ast, t_ast *new_son);
t_ast						*get_ast_copy(t_ast *ast);
void						ast_printer(t_ast *ast, char *filename);
void						free_lists(void);
void						free_fun_lists(void);

#endif
