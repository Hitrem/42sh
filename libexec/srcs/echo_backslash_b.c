/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_backslash_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:20:34 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 12:24:09 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void		cmd_back(t_echo *ech)
{
	int	i;
	int	k;

	ech->cmd[ech->i] = '\n';
	++ech->i;
	i = ech->i;
	k = 0;
	while (k < i - 1)
	{
		ech->cmd[ech->i] = ' ';
		ech->i++;
		++k;
	}
	++ech->arg;
}

t_echo			*replace_backslash(t_echo *ech, int z)
{
	if (z == 1)
	{
		ech->cmd[ech->i] = '\n';
		++ech->i;
		++ech->arg;
	}
	else if (z == 2)
	{
		ech->cmd[ech->i] = '\t';
		++ech->i;
		++ech->arg;
	}
	else if (z == 3)
		cmd_back(ech);
	return (ech);
}

char			*each_character(t_ast *tmp, int val, t_echo *ech)
{
	while (!(ech->arg = 0) && tmp)
	{
		while (ech->arg < strlen(tmp->token->token))
		{
			while (ech->i >= val - 1)
			{
				ech->cmd = realloc(ech->cmd, val);
				val *= 2;
			}
			if (ech->e == 1)
			{
				ech = option_e(tmp, ech);
				if (ech->cut == 1)
					return (ech->cmd);
			}
			else
				ech = print_var_or_option_e(tmp, ech);
			++ech->arg;
		}
		if (tmp->brother)
			ech->cmd[ech->i] = ' ';
		++ech->i;
		tmp = tmp->brother;
	}
	return (ech->cmd);
}

t_echo			*print_var_or_option_e(t_ast *tmp, t_echo *ech)
{
	if (tmp->token->type == VARIABLE)
		ech = variable_print(tmp, ech);
	else if (tmp->token->token[ech->arg] != '\\')
		no_option_e(tmp, ech, 1);
	else
	{
		ech->cmd[ech->i] = '\\';
		ech->i += 1;
	}
	return (ech);
}
