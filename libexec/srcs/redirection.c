/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:21:33 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/27 06:07:07 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "exec.h"
#include "readline.h"
#include "redirection.h"

int			read_redirection_list(t_red *red, char *cmd,
		t_red_cmd *list, t_ast *node)
{
	while (red)
	{
		if (red->type == RREDIR)
			redir_great(red);
		else if (red->type == LREDIR)
			redir_less(red);
		else if (red->type == DGREAT)
			redir_great(red);
		else if (red->type == DLESS)
			redir_less(red);
		else if (red->type == DLESSDASH)
			redir_less(red);
		else if (red->type == GREATAND)
			redir_great(red);
		else if (red->type == LESSAND)
			redir_less(red);
		else if (red->type == CLOBBER)
			redir_great(red);
		else if (red->type == LESSGREAT)
			redir_less(red);
		red = red->next;
	}
	return (execute_cmd(cmd, list, node));
}

t_red		*add_red(int ionumber, t_type type, char *word, t_red *red)
{
	t_red	*new;
	t_red	*tmp;

	new = malloc(sizeof(t_red));
	if (ionumber == -1)
	{
		if (type == RREDIR || type == DGREAT || type == GREATAND
				|| type == CLOBBER)
			new->ionumber = 1;
		else
			new->ionumber = 0;
	}
	else
		new->ionumber = ionumber;
	new->type = type;
	new->set_fd = -1;
	new->word = word;
	new->next = NULL;
	if (red == NULL)
		return (new);
	tmp = red;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (red);
}

char		*make_cmd(t_ast *tmp, int *i, char *cmd)
{
	int		j;
	char	*tok_cmd;

	tok_cmd = tmp->token->token;
	j = 0;
	while (tok_cmd[j])
	{
		cmd = realloc(cmd, sizeof(char) * (*i + 1));
		cmd[*i] = tok_cmd[j];
		++*i;
		j++;
	}
	if (*i != 0)
	{
		cmd = realloc(cmd, sizeof(char) * (*i + 1));
		cmd[*i] = ' ';
		++*i;
	}
	cmd = realloc(cmd, sizeof(char) * (*i + 1));
	cmd[*i] = '\0';
	return (cmd);
}
