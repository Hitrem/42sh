/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 13:04:21 by pferry            #+#    #+#             */
/*   Updated: 2014/01/31 13:08:14 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		main(int argc, char **argv, char **environ)
{
	char	*line;
	char	**save;
	char	**env;
	t_list	*lst;

	argv[argc - argc] = argv[argc - argc];
	env = ft_tabdub(environ);
	while (ft_putstr("$>"), get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp(ft_strtrim(line), ""))
			continue;
		lst = ft_lexer(line, 0, 0);
		while (lst)
		{
			if (ft_is_spe_char(lst->content[0]) == 1)
			{
				save = ft_strsplit(lst->content, ' ');
				if (!lst->next || lst->next->content[0] == ';')
					env = ft_simple_cmd(save, env);
				else if (lst->next && lst->next->content[0] == '|')
				{
					if (!lst->next->next || !lst->next->next->content)
						ft_error("Usage is cm1 | cm2");
					env = ft_pipe_cmd(save, env, lst->next->next->content);
				}
			}
			lst = lst->next;
		}
	}
	return (0);
}
