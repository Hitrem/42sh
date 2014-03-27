/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 01:48:28 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 06:16:46 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include <stdio.h>
# include <stdlib.h>
# include "readline.h"

typedef struct s_aliases		t_aliases;

struct				s_aliases
{
	char			*alias;
	char			*original;
	t_aliases		*next;
};

typedef struct		s_echo
{
	int				n;
	int				e;
	int				opt;
	int				num_opt;
	int				i;
	unsigned int	arg;
	int				cut;
	int				slash;
	char			*cmd;
}					t_echo;

extern t_aliases	*g_alias;
int					ft_echo(t_ast *node);
t_echo				*get_options(t_ast *node, t_echo *ech);
char				*build_cmd(t_ast *node, int val, t_echo *ech);
t_aliases			*alias(t_ast *node);
int					find_alias(char *name, t_aliases *g_alias);
char				*value_alias(char *name, t_aliases *g_alias, int a);
void				free_alias(void);
t_aliases			*unalias(t_ast *node);
int					my_exit(t_ast *node);
int					my_cd(t_ast *node);

#endif
