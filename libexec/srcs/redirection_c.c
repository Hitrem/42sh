/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:48:05 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 12:42:57 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "exec.h"
#include "readline.h"
#include "redirection.h"

static void	ft_while(t_red_cmd **list, t_ast *node, int *cpt, int **i)
{
	(*list)->tmp = tmp_become_brother((*list)->tmp, 0, node);
	*i = malloc(sizeof(int));
	**i = 0;
	while (((*list)->tmp->tmp->token->type < RREDIR
				|| (*list)->tmp->tmp->token->type > PIPE)
			&& ((*list)->tmp->tmp->token->type != IO_NUMBER))
		*list = is_rword(*list, *i, node);
	(*list)->tmp = tmp_brother((*list)->tmp, 1, node);
	free(*i);
	*cpt = 1;
}

t_red_cmd	*redir_enumeration(t_ast *node, t_red_cmd *list)
{
	int		cpt;
	int		*i;

	cpt = 0;
	while (list->tmp->tmp)
	{
		if (list->tmp->tmp->token->type >= RREDIR
				&& list->tmp->tmp->token->type <= PIPE
				&& cpt != 0)
			list = change_list(list, node);
		else if (list->tmp->tmp->token->type == IO_NUMBER)
			list->tmp = tmp_become_brother(list->tmp, 1, node);
		else
			ft_while(&list, node, &cpt, &i);
	}
	return (list);
}
