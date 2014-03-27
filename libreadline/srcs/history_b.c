/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:21:02 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 05:39:28 by jwoodrow         ###   ########.fr       */
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

void			init_hist(void)
{
	g_hist = NULL;
	if (g_pid_loop->is_in_loop)
	{
		if ((g_hist = malloc(sizeof(t_history))) == NULL)
			write(2, "42sh: history corrupted or no more memory\n", 42);
		g_hist->previous = g_hist;
		g_hist->next = g_hist;
		g_hist->last = NULL;
		g_hist->exist = 1;
		g_current_hist = g_hist;
		init_from_file();
	}
	if ((g_current_cmd = malloc(sizeof(t_history))) == NULL)
		write(2, "42sh: history corrupted or no more memory\n", 42);
	g_current_cmd->previous = NULL;
	g_current_cmd->next = NULL;
	g_current_cmd->last = NULL;
}
