/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_backslash_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:25:08 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 05:27:25 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_echo	*variable_print(t_ast *tmp, t_echo *ech)
{
	char	*nam;
	char	*val;
	int		i;

	nam = my_strcpy(tmp->token->token);
	val = find_var(nam, g_var);
	free(nam);
	if (val != NULL)
	{
		i = 0;
		while (val[i])
		{
			ech->cmd[ech->i] = val[i];
			++ech->i;
			i++;
		}
		ech->cmd[ech->i] = '\0';
		ech->arg += strlen(val);
	}
	else
	{
		--ech->i;
		ech->cmd[ech->i] = '\0';
	}
	return (ech);
}
