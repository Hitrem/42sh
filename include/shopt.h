/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shopt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:23:14 by pferry            #+#    #+#             */
/*   Updated: 2014/03/27 12:40:50 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOPT_H
# define SHOPT_H

# include "parser.h"
# include "readline.h"

typedef	struct s_shpt	t_shpt;
struct					s_shpt
{
	char				*name;
	char				*on_off;
	t_shpt				*next;
};
extern t_shpt			*g_shpt;

int						my_shopt(t_ast *node);
t_shpt					*init_shopt(void);
void					free_shopt(void);
t_shpt					*add_shopt(char *name, char *on_off);
void					print_shopt(t_shpt *g_shpt);
void					print_valid(t_ast *node);
void					print_invalid(t_ast *node, int i);
void					print_invalid_argument(t_ast *tmp);
void					print_o_positive(t_shpt *g_shpt);
void					valid_or_not_valid(t_ast *tmp);
int						option_q(t_ast *node);
void					option_on(t_shpt *g_shpt, t_ast *node);
void					option_off(t_shpt *g_shpt, t_ast *node);
void					change_var(t_ast *node, t_shpt *g_shpt, int i);
int						check_option_used(t_ast *node, char *set);
int						error_message_usage(t_ast *tmp, int i);
int						check_return_value(t_ast *node, int i);
int						find_optname(char *optname, t_shpt *g_shpt);

#endif
