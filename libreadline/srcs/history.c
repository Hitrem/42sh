/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 00:49:20 by sde-segu          #+#    #+#             */
/*   Updated: 2014/03/27 12:41:55 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "my_string.h"
#include "readline.h"

void			init_from_file(void)
{
	char	*line;
	int		it;
	int		tmp;
	int		len;
	char	*last;

	line = readfile(".42sh_history", 1);
	it = 0;
	if (line != NULL)
	{
		//
		len = strlen(line);
		while (it < len)
		{
			tmp = it;
			while (line[it] != '\n')
				it++;
			line[it] = 0;
			//
			last = my_strcpy(line + tmp);
			add_line_history(last, 1);
			it++;
			free(last);
		}
		free(line);
	}
}

void			add_line_history(char *line, int exist)
{
	t_history	*current;

	if (line != NULL && strcmp(line, "") && g_pid_loop->is_in_loop)
	{
		current = NULL;
		current = malloc(sizeof(t_history));
		//
		current->last = my_strcpy(line);
		current->previous = g_hist;
		current->next = g_hist->next;
		current->next->previous = current;
		current->exist = exist;
		g_hist->next = current;
		g_hist = current;
	}
}

static void		rec_free(t_history *node)
{
	if (node->last != NULL)
		rec_free(node->previous);
	free(node->last);
	free(node);
}

static void		write_history(t_history *list)
{
	char	*line;
	int		size;
	int		fd;

	fd = open(".42sh_history", O_CREAT | O_RDWR | O_APPEND,
		S_IRUSR | S_IWUSR);
	if (fd == -1)
		return ;
	while (list->last != NULL)
	{
		line = list->last;
		//
		size = strlen(line);
		line[size] = '\n';
		if (!list->exist)
			write(fd, line, size + 1);
		list = list->next;
	}
	close(fd);
}

void			free_hist(void)
{
	write_history(g_hist->next->next);
	rec_free(g_hist);
}
