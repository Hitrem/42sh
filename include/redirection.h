/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:35:13 by pferry            #+#    #+#             */
/*   Updated: 2014/03/27 06:20:41 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "exec.h"

typedef struct s_readred	t_readred;
struct						s_readred
{
	t_ast					*tmp;
	t_ast					*tmp_prev;
};

typedef struct s_red		t_red;
struct						s_red
{
	int						ionumber;
	t_type					type;
	char					*word;
	int						old;
	int						fd;
	int						error;
	int						set_fd;
	t_red					*next;
};

typedef	struct s_red_cmd	t_red_cmd;
struct						s_red_cmd
{
	char					*cmd;
	t_red					*red;
	t_readred				*tmp;
};

int							redir_less(t_red *red);
int							redir_great(t_red *red);
int							execute_redirection(t_ast *redir
	, t_ast *red);
int							check_redirection(t_ast *node);
t_readred					*tmp_become_brother(t_readred *tmp
	, int i, t_ast *node);
t_readred					*tmp_brother(t_readred *tmp
	, int i, t_ast *node);
void						free_list(t_red_cmd *list);
int							build_builtin(char **cmd_tab
	, t_red_cmd *list);
int							fork_and_wait(char **cmd_tab
	, t_red_cmd *list, t_ast *node);

int							less_input(t_red *red);
int							heredoc(t_red *red);
int							tab_heredoc(t_red *red);
int							duplic_input(t_red *red);
int							read_write(t_red *red);

t_red_cmd					*change_list(t_red_cmd *list, t_ast *node);
t_red_cmd					*is_rword(t_red_cmd *list, int *i, t_ast *node);

int							read_redirection_list(t_red *red, char *cmd
	, t_red_cmd *list, t_ast *node);
int							execute_cmd(char *cmd, t_red_cmd *list
	, t_ast *node);

t_red_cmd					*redir_enumeration(t_ast *node, t_red_cmd *list);
t_red						*add_red(int ionumber, t_type type, char *word
	, t_red *red);
char						*make_cmd(t_ast *tmp, int *i, char *cmd);

t_red						*check_io_number(t_red *red, t_ast *tmp
	, t_ast *tmp_prev);

#endif
