/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 12:10:24 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 12:42:58 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "exec.h"
#include "readline.h"
#include "redirection.h"

static void	ft_init(int *i, int *j, int *k, char ***cmd_tab)
{
	*i = 0;
	*j = 0;
	*k = 0;
	*cmd_tab = NULL;
}

static void	ft_func(int *i, int j, int *k, char ***cmd_tab)
{
	(*cmd_tab)[*i] = realloc((*cmd_tab)[*i], sizeof(char) * (j + 1));
	(*cmd_tab)[*i][j] = '\0';
	++*i;
	++*k;
}

int			execute_cmd(char *cmd, t_red_cmd *list, t_ast *node)
{
	char	**cmd_tab;
	int		i;
	int		j;
	int		k;

	ft_init(&i, &j, &k, &cmd_tab);
	while (cmd[k] && !(j = 0))
	{
		cmd_tab = realloc(cmd_tab, sizeof(char*) * (i + 1));
		cmd_tab[i] = NULL;
		while (cmd[k] != ' ')
		{
			cmd_tab[i] = realloc(cmd_tab[i], sizeof(char) * (j + 1));
			cmd_tab[i][j] = cmd[k];
			++j;
			++k;
		}
		ft_func(&i, j, &k, &cmd_tab);
	}
	cmd_tab = realloc(cmd_tab, sizeof(char*) * (i + 1));
	cmd_tab[i] = NULL;
	if (check_builtin(cmd_tab[0]) == 1)
		return (build_builtin(cmd_tab, list));
	return (fork_and_wait(cmd_tab, list, node));
}
