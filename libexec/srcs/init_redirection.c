/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:21:33 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 05:33:11 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "redirection.h"

static void		unset_fd(t_red_cmd *list)
{
	t_red	*tmp;
	int		err;

	if (list->red->set_fd == 1)
		return ;
	tmp = list->red;
	while (tmp->set_fd == -1 && tmp->next && tmp->next->set_fd == -1)
		tmp = tmp->next;
	if (tmp->error == 2)
	{
		err = dup(tmp->ionumber);
		dup2(2, err);
	}
	dup2(tmp->old, tmp->ionumber);
	if (tmp->fd != 0)
		close(tmp->fd);
	tmp->set_fd = 1;
	unset_fd(list);
}

void			free_list(t_red_cmd *list)
{
	t_red	*tmp2;

	free(list->cmd);
	unset_fd(list);
	while (list->red)
	{
		tmp2 = list->red->next;
		fflush(NULL);
		free(list->red);
		list->red = tmp2;
	}
	free(list->tmp->tmp);
	free(list->tmp);
	free(list);
}

static int		change_return(int status, t_ast *node)
{
	if (status != 0)
	{
		if (status > 512)
		{
			node->return_value = 127;
			g_pid_loop->return_value = 127;
		}
		else
		{
			node->return_value = 1;
			g_pid_loop->return_value = 1;
		}
	}
	if (g_pid_loop->bang == 1)
	{
		g_pid_loop->bang = 0;
		if (g_pid_loop->return_value == 0)
			g_pid_loop->return_value = 1;
		else if (g_pid_loop->return_value != -1)
			g_pid_loop->return_value = 0;
	}
	return (g_pid_loop->return_value);
}

static void		wait_for_it(t_ast *node, int status)
{
	waitpid(g_pid_loop->pid, &status, 0);
	node->return_value = status;
	if (g_pid_loop->return_value != 127)
		g_pid_loop->return_value = status;
}

int				fork_and_wait(char **cmd_tab, t_red_cmd *list, t_ast *node)
{
	int		status;
	int		i;

	status = 0;
	g_pid_loop->pid = fork();
	if (g_pid_loop->pid == 0)
	{
		if (execvp(cmd_tab[0], cmd_tab) == -1)
		{
			g_pid_loop->return_value = 127;
			fprintf(stderr, "42sh: command not found: %s\n", cmd_tab[0]);
			exit(127);
		}
	}
	else
		wait_for_it(node, status);
	g_pid_loop->return_value = change_return(status, node);
	free_list(list);
	i = 0;
	while (cmd_tab[i])
		free(cmd_tab[i++]);
	free(cmd_tab);
	return (0);
}
