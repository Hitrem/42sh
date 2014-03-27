/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:37:04 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 05:40:24 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void			write_simple_echo(t_echo *ech)
{
	write(1, ech->cmd, strlen(ech->cmd));
	write(1, "\n", 1);
}

t_echo			*block_of_options(t_echo *ech, t_ast *tmp)
{
	int i;

	i = 1;
	while (tmp->token->token[i])
	{
		if (tmp->token->token[i] == 'n')
		{
			++i;
			ech->n = 1;
		}
		if (tmp->token->token[i] == 'e')
		{
			++i;
			ech->e = 1;
		}
		if (tmp->token->token[i] == 'E')
		{
			++i;
			ech->e = 0;
		}
	}
	return (ech);
}

t_echo			*init_echo(t_ast *node)
{
	t_echo *ech;

	ech = malloc(sizeof(t_echo));
	ech->num_opt = 0;
	ech = get_options(node, ech);
	ech->cmd = NULL;
	ech->cmd = calloc(sizeof(char), 128);
	return (ech);
}
