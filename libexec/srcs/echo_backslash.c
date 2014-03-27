/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_backslash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:21:33 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 07:39:44 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_echo			*ebackslash(t_ast *tmp, t_echo *ech, int y)
{
	if (y == 1)
	{
		ech->cmd[ech->i] = '\\';
		ech->cmd[ech->i + 1] = tmp->token->token[ech->arg + 1];
		ech->arg += 2;
		++ech->i;
	}
	else if (y == 2)
	{
		--ech->i;
		++ech->arg;
	}
	else if (y == 3)
	{
		ech->cmd[ech->i] = '\0';
		ech->n = 1;
		ech->cut = 1;
	}
	else if (y == 4)
	{
		ech->i = 0;
		++ech->arg;
	}
	return (ech);
}

t_echo			*no_option_e(t_ast *tmp, t_echo *ech, int w)
{
	if (w == 1)
	{
		ech->cmd[ech->i] = tmp->token->token[ech->arg];
		++ech->i;
	}
	else if (w == 2)
	{
		ech->cmd[ech->i] = tmp->token->token[ech->arg];
		++ech->i;
	}
	return (ech);
}

t_echo			*option_e_bis(t_ast *tmp, t_echo *ech, int x)
{
	if (x == 1)
	{
		if (tmp->token->token[ech->arg] == '\\'
				&& tmp->token->token[ech->arg + 1] == 'n')
			ech = replace_backslash(ech, 1);
		else if (tmp->token->token[ech->arg] == '\\'
				&& tmp->token->token[ech->arg + 1] == 't')
			ech = replace_backslash(ech, 2);
		else if (tmp->token->token[ech->arg] == '\\'
				&& tmp->token->token[ech->arg + 1] == 'v')
			ech = replace_backslash(ech, 3);
		else if (tmp->token->type == VARIABLE)
			ech = variable_print(tmp, ech);
		else
			ech = no_option_e(tmp, ech, 2);
	}
	if (x == 2)
	{
		--ech->i;
		ech->cmd = realloc(ech->cmd, ech->i + 1);
		ech->cmd[ech->i] = '\0';
	}
	return (ech);
}

t_echo			*option_e(t_ast *tmp, t_echo *ech)
{
	char *tok;

	tok = tmp->token->token;
	if (tok[ech->arg] == '\\' && tok[ech->arg + 1] == '\\')
		ech = ebackslash(tmp, ech, 1);
	else if (tok[ech->arg] == '\\' && tok[ech->arg + 1] == 'a')
		++ech->arg;
	else if (tok[ech->arg] == '\\' && tok[ech->arg + 1] == 'b')
		ech = ebackslash(tmp, ech, 2);
	else if (tok[ech->arg] == '\\' && tok[ech->arg + 1] == '\\'
			&& tok[ech->arg + 2] == 'c')
		ech = ebackslash(tmp, ech, 3);
	else if (tok[ech->arg] == '\\' && tok[ech->arg + 1] == '\\'
			&& tok[ech->arg + 2] == 'e')
		ech->arg += 2;
	else if (tok[ech->arg] == '\\' && tok[ech->arg + 1] == 'f')
		ech = replace_backslash(ech, 3);
	else if (tok[ech->arg] == '\\' && tok[ech->arg + 1] == 'r')
		ech = ebackslash(tmp, ech, 4);
	else
		return (option_e_bis(tmp, ech, 1));
	return (ech);
}

char			*build_cmd(t_ast *node, int val, t_echo *ech)
{
	t_ast	*tmp;

	tmp = node;
	ech->i = 0;
	ech->cut = 0;
	if (tmp == NULL)
	{
		free(ech->cmd);
		return (NULL);
	}
	ech->cmd = each_character(tmp, val, ech);
	if (ech->e == 1)
		option_e_bis(tmp, ech, 2);
	return (ech->cmd);
}
