/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompts_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:49:22 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 07:25:15 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "prompts.h"
#include "local_var.h"
#include "readline.h"
#include "history.h"
#include "parser.h"
#include "exec.h"
#include "source.h"

void			add_str(char **str1, char *str2)
{
	size_t		i;
	int			len;

	len = *str1 ? strlen(*str1) : 0;
	//
	*str1 = realloc(*str1, sizeof(char) * (len + strlen(str2) + 1));
	i = 0;
	//
	while (i < strlen(str2))
	{
		(*str1)[len + i] = str2[i];
		i++;
	}
	//
	(*str1)[len + strlen(str2)] = 0;
}

void			init_prompt(void)
{
	init_term();
	init_hist();
}

void			free_prog(char *buff, t_ast *tree, int tty)
{
	if (tree)
		free(tree);
	restore_term(tty, 1, 0, 0);
	if (g_pid_loop->is_in_loop)
		free_hist();
	free(g_pid_loop);
	return ;
	buff++;
}

static void		ft_func(int save)
{
	g_pid_loop->is_in_loop = 1;
	init_prompt();
	g_pid_loop->is_in_loop = save;
	g_pid_loop->heredoc = 1;
}

char			*ps2_loop(char *head, char *eof, int tty)
{
	char	*buff;
	char	*ret;
	int		save;

	buff = NULL;
	ret = malloc(sizeof(char));
	save = g_pid_loop->is_in_loop;
	if (!save)
		ft_func(save);
	while (1)
	{
		if (tty)
			printf("%s> ", head);
		fflush(NULL);
		readline2(&buff, NULL, '\n');
		if (!strcmp(buff, eof))
			break ;
		add_str(&ret, buff);
	}
	if (!save)
		restore_term(1, 1, 0, 0);
	return (ret);
}
