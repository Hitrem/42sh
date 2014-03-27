/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:15:20 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 06:10:57 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "check_options.h"
#include "shopt.h"

static void			init_rc(void)
{
	return ;
}

static int			ft_if(char **argv, int i, int *rc_exec)
{
	//
	if (strcmp(argv[i], "--ast-print") == 0)
		g_shpt->on_off = "on";
	//
	else if (strcmp(argv[i], "-O") == 0)
		print_shopt(g_shpt);
	//
	else if (strcmp(argv[i], "+O") == 0)
		print_o_positive(g_shpt);
	//
	else if (strcmp(argv[i], "-c") == 0 && argv[i + 1])
		return (2);
	//
	else if (strcmp(argv[i], "-c") == 0)
		return (need_argument());
	//
	else if (strcmp(argv[i], "--norc") == 0)
		*rc_exec = 0;
	//
	else if (argv[i][0] == '-')
		return (print_error_msg(argv, i));
	else
		return (-1);
	return (-1337);
}

int					check_loop(int argc, char *argv[])
{
	int			i;
	int			rc_exec;
	int			ret;

	i = 1;
	rc_exec = 1;
	while (i < argc)
	{
		ret = ft_if(argv, i, &rc_exec);
		if (ret != -1337)
			return (ret);
		i++;
	}
	g_pid_loop->is_in_loop = 0;
	if (rc_exec)
		init_rc();
	return (-3);
}
