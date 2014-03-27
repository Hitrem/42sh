/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:21:33 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 07:06:37 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "exec.h"
#include "readline.h"

static int	change_dir(char *path)
{
	if (!strcmp(path, "-"))
		return (chdir(getenv("PREV_PWD")));
	else
		return (chdir(path));
}

static int	error_message(t_ast *node)
{
	fprintf(stderr, "42sh: cd: %s: %s\n", node->brother->token->token,
			strerror(errno));
	g_pid_loop->return_value = 1;
	return (1);
}

static int	print_error(char *cwd)
{
	fprintf(stderr, "42sh: setenv: %s\n", strerror(errno));
	g_pid_loop->return_value = 1;
	free(cwd);
	return (1);
}

static int	cd_ret(char **cwd, t_ast *node)
{
	free(*cwd);
	write(1, "test\n", 5);
	return (error_message(node));
}

int			my_cd(t_ast *node)
{
	int		ret;
	char	*home;
	char	*cwd;

	ret = 0;
	home = getenv("HOME");
	cwd = NULL;
	cwd = getcwd(NULL, 0);
	if (node->brother == NULL)
		ret = chdir(home);
	else
		ret = change_dir(node->brother->token->token);
	if (ret)
		return (cd_ret(&cwd, node));
	setenv("PREV_PWD", cwd, 1);
	free(cwd);
	cwd = getcwd(NULL, 0);
	ret = setenv("PWD", cwd, 1);
	if (ret)
		return (print_error(cwd));
	free(cwd);
	g_pid_loop->return_value = 0;
	return (0);
}
