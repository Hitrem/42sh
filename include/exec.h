/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:04:16 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 07:40:47 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <assert.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "parser.h"
# include "function.h"
# include "my_string.h"
# include "builtin.h"
# include "shopt.h"
# include "readline.h"

typedef struct s_var		t_var;

struct						s_var
{
	char					*name;
	char					*val;
	t_var					*next;
};

extern t_var				*g_var;

int							init_var_function(t_ast *node);
int							statements(t_ast *node);
int							type_node(t_ast *node);
int							exec_if(t_ast *ast);
int							exec_cmd(t_ast *node);
int							or_exec(t_ast *ast);
int							and_exec(t_ast *ast);
int							exec_while(t_ast *ast);
int							exec_until(t_ast *ast);
int							my_pipe(t_ast *ast);
t_var						*new_var(t_ast *node);
t_var						*init_var(int argc, char *param[]);
char						*find_var(char *val, t_var *g_var);
t_var						*add_var(char *variable, char *value
	, t_var *g_var);
void						free_variables(void);
int							exec_for(t_ast *ast);
int							list_redirection(t_ast *node);
int							check_builtin(char *cmd);
int							call_builtin(t_ast *node, char *cmd);
int							set_fork(void);
void						set_pipe(int *pipefd);

void						print_alias(t_ast *node);
char						*value_alias(char *name, t_aliases *g_alias
	, int a);
int							find_alias(char *name, t_aliases *g_alias);
t_aliases					*sort_list_alias(t_aliases *new);

char						*use_variable(char *variable);
char						**command_center(t_ast *node);
int							execution(t_ast *node);
int							status_change(t_ast *node, int status);
int							fork_and_execute(t_ast *node);

t_echo						*option_e(t_ast *tmp, t_echo *ech);
t_echo						*option_e_bis(t_ast *tmp, t_echo *ech, int x);
t_echo						*print_var_or_option_e(t_ast *tmp, t_echo *ech);
t_echo						*replace_backslash(t_echo *ech, int z);
t_echo						*variable_print(t_ast *tmp, t_echo *ech);
t_echo						*no_option_e(t_ast *tmp, t_echo *ech, int w);
t_echo						*ebackslash(t_ast *tmp, t_echo *ech, int y);
char						*each_character(t_ast *tmp, int val, t_echo *ech);

void						write_simple_echo(t_echo *ech);
t_echo						*block_of_options(t_echo *ech, t_ast *tmp);
t_echo						*init_echo(t_ast *node);

int							turn_change(int turn, t_ast *tmpnode, int x);
t_aliases					*free_part(t_ast *tmpnode);
t_aliases					*free_in_the_middle(t_aliases *tmp);
t_ast						*error_unalias(t_ast *node, int j);

t_var						*init2_var(int argc, char *param[], t_var *g_var);
t_var						*init3_var(int argc, char *param[], t_var *g_var);
int							var_exist(char *name, t_var *g_var);
t_var						*vchange_value(char *name, char *value
	, t_var *g_var);

#endif
