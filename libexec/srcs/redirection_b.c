/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:44:27 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 06:20:47 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "exec.h"
#include "readline.h"
#include "redirection.h"

t_red_cmd	*change_list(t_red_cmd *list, t_ast *node)
{
	list->red = check_io_number(list->red,
			list->tmp->tmp, list->tmp->tmp_prev);
	list->tmp = tmp_become_brother(list->tmp, 2, node);
	return (list);
}

t_red_cmd	*is_rword(t_red_cmd *list, int *i, t_ast *node)
{
	list->cmd = make_cmd(list->tmp->tmp, i, list->cmd);
	list->tmp = tmp_brother(list->tmp, 0, node);
	return (list);
}

t_red		*check_io_number(t_red *red, t_ast *tmp, t_ast *tmp_prev)
{
	if (tmp_prev->token->type == IO_NUMBER)
		red = add_red(atoi(tmp_prev->token->token),
				tmp->token->type, tmp->brother->token->token, red);
	else
		red = add_red(-1, tmp->token->type,
				tmp->brother->token->token, red);
	return (red);
}

int			list_redirection(t_ast *node)
{
	t_red_cmd *list;

	list = malloc(sizeof(t_red_cmd));
	list->cmd = NULL;
	list->red = NULL;
	list->tmp = NULL;
	list->tmp = malloc(sizeof(t_readred));
	list->tmp->tmp = node->first_son->brother;
	list->tmp->tmp_prev = node->first_son;
	list = redir_enumeration(node, list);
	read_redirection_list(list->red, list->cmd, list, node);
	return (g_pid_loop->return_value);
}
