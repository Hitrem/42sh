/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:21:33 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 02:42:38 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shopt.h"
#include "readline.h"
#include "exec.h"

void	free_shopt(void)
{
	t_shpt	*tmp;

	while (g_shpt)
	{
		tmp = g_shpt->next;
		free(g_shpt);
		g_shpt = tmp;
	}
}

void	free_variables(void)
{
	t_var	*tmp;

	while (g_var)
	{
		tmp = g_var->next;
		free(g_var->val);
		free(g_var->name);
		free(g_var);
		g_var = tmp;
	}
}

void	free_alias(void)
{
	t_aliases	*tmp;

	while (g_alias)
	{
		tmp = g_alias->next;
		free(g_alias->alias);
		free(g_alias->original);
		free(g_alias);
		g_alias = tmp;
	}
}
