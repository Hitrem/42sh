/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:13:30 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 02:41:34 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

typedef struct s_funct		t_funct;
struct			s_funct
{
	char		*name;
	t_ast		*function;
	t_funct		*next;
};

extern t_funct	*g_funct;
t_funct			*new_funct(t_ast *node);
int				find_funct(char *name, t_funct *funct);
int				execute_funct(char *name);

void			free_funct(void);

#endif
