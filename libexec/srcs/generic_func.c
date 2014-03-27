/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:21:33 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/26 20:52:08 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		set_fork(void)
{
	int pid;

	if ((pid = fork()) == -1)
	{
		write(2, "fork error.\n", 12);
		exit(EXIT_FAILURE);
	}
	return (pid);
}

void	set_pipe(int *pipefd)
{
	int error;

	error = pipe(pipefd);
	if (error == -1)
	{
		write(2, "pipe fork error.\n", 17);
		exit(EXIT_FAILURE);
	}
}
