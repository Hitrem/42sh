/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_less.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:21:33 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 05:43:53 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <errno.h>
#include "exec.h"
#include "redirection.h"
#include "prompts.h"

int				redir_less(t_red *red)
{
	if (red->type == LREDIR)
		return (less_input(red));
	else if (red->type == DLESS)
		return (heredoc(red));
	else if (red->type == LESSAND)
		return (duplic_input(red));
	else if (red->type == LESSGREAT)
		return (read_write(red));
	else if (red->type == DLESSDASH)
		return (tab_heredoc(red));
	return (0);
}
