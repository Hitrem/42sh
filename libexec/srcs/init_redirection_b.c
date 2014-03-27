/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redirection_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:29:21 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 06:06:14 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "redirection.h"

t_readred		*tmp_brother(t_readred *tmp, int i, t_ast *node)
{
	if (i == 0)
	{
		if (tmp->tmp_prev == NULL)
			tmp->tmp_prev = node->first_son;
		else
			tmp->tmp_prev = tmp->tmp_prev->brother;
		tmp->tmp = tmp->tmp->brother;
	}
	else if (i == 1)
	{
		if (tmp->tmp == tmp->tmp_prev)
			tmp->tmp = tmp->tmp->brother;
	}
	return (tmp);
}

t_readred		*tmp_become_brother(t_readred *tmp, int i, t_ast *node)
{
	if (i == 0)
	{
		if (tmp->tmp_prev == node->first_son
				|| tmp->tmp_prev == node->first_son->brother)
		{
			tmp->tmp_prev = NULL;
			tmp->tmp = node->first_son;
		}
	}
	else if (i == 1)
	{
		tmp->tmp = tmp->tmp->brother;
		tmp->tmp_prev = tmp->tmp_prev->brother;
	}
	else if (i == 2)
	{
		tmp->tmp = tmp->tmp->brother->brother;
		tmp->tmp_prev = tmp->tmp_prev->brother->brother;
	}
	return (tmp);
}
