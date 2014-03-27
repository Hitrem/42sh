/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-segu <sde-segu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 12:21:17 by sde-segu          #+#    #+#             */
/*   Updated: 2014/03/27 06:10:57 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "check_options.h"
#include "shopt.h"

static void			print_error(char *argv)
{
	write(STDERR_FILENO, "42sh: ", 6);
	write(STDERR_FILENO, argv, strlen(argv));
	write(STDERR_FILENO, ": invalid option\n\n", 18);
	write(STDERR_FILENO, "Usage:\t./42sh [option] ...\n", 27);
	write(STDERR_FILENO, "\t./42sh [option] script-file ...\n\n", 35);
	write(STDERR_FILENO, "option:\t-c <command>\t\tExecute the", 33);
	write(STDERR_FILENO, " command 'command'.\n", 20);
	write(STDERR_FILENO, "\t--version\t\tPrint the current", 29);
	write(STDERR_FILENO, " 42sh version.\n", 15);
	write(STDERR_FILENO, "\t--ast-print\t\tEnable the ast", 28);
	write(STDERR_FILENO, " printer.\n", 10);
	write(STDERR_FILENO, "\t--norc\t\t\tDisable the", 21);
	write(STDERR_FILENO, " resource reader.\n", 18);
	write(STDERR_FILENO, "\t[-+]O [shopt_option]\tIf shopt_option", 37);
	write(STDERR_FILENO, " is set, -O sets the value of\n", 31);
	write(STDERR_FILENO, "\t\t\t\t that option. +O unsets it.\n", 32);
}

int					need_argument(void)
{
	write(1, "42sh: -c: option requires an argument\n", 38);
	return (-2);
}

int					print_error_msg(char *argv[], int i)
{
	print_error(argv[i]);
	return (-2);
}

int					check_opt(int argc, char *argv[])
{
	int res;

	if (argc > 1 && strcmp(argv[1], "--version") == 0)
	{
		write(1, "Version 1.0\n", 12);
		return (0);
	}
	else
	{
		res = check_loop(argc, argv);
		return (res);
	}
}
