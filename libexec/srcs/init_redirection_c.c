/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redirection_c.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:31:29 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 06:06:25 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "redirection.h"

static t_ast	*add_redir(t_ast *redir, char **cmd_tab, int i)
{
	t_ast	*new;
	t_ast	*tmp;

	new = malloc(sizeof(t_ast));
	new->token = NULL;
	new->token = malloc(sizeof(t_token));
	new->brother = NULL;
	new->first_son = NULL;
	new->token->type = WORD;
	new->token->token = NULL;
	new->token->token = calloc(sizeof(char), my_strlen(cmd_tab[i]) + 1);
	memcpy(new->token->token, cmd_tab[i], my_strlen(cmd_tab[i]));
	tmp = redir;
	while (tmp->brother)
		tmp = tmp->brother;
	tmp->brother = new;
	return (redir);
}

static void		free_redir_ast(t_ast *node, t_red_cmd *list)
{
	t_ast	*tmp;

	while (node)
	{
		tmp = node->brother;
		free(node->token->token);
		free(node->token);
		free(node);
		node = tmp;
	}
	free_list(list);
}

int				build_builtin(char **cmd_tab, t_red_cmd *list)
{
	int			i;
	t_ast		*redir;

	redir = malloc(sizeof(t_ast));
	redir->first_son = NULL;
	redir->token = NULL;
	redir->token = malloc(sizeof(t_token));
	redir->token->token = NULL;
	redir->token->token = malloc(sizeof(char) * strlen(cmd_tab[0]));
	memcpy(redir->token->token, cmd_tab[0], strlen(cmd_tab[0]));
	redir->token->type = WORD;
	redir->brother = NULL;
	i = 1;
	while (cmd_tab[i])
		redir = add_redir(redir, cmd_tab, i++);
	call_builtin(redir, cmd_tab[0]);
	free_redir_ast(redir, list);
	i = 0;
	while (cmd_tab[i])
		free(cmd_tab[i++]);
	free(cmd_tab);
	return (g_pid_loop->return_value);
}
