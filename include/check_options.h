/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:01:04 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 06:10:56 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_OPTIONS_H
# define CHECK_OPTIONS_H
# define SHOPT_NB 8

int							check_opt(int argc, char *argv[]);
int							check_loop(int argc, char *argv[]);
int							need_argument(void);
int							print_error_msg(char *argv[], int i);

typedef struct s_shopt		t_shopt;

struct						s_shopt
{
	const char				*name[SHOPT_NB];
	const char				*default_val[SHOPT_NB];
	const char				*default_set[SHOPT_NB];
};

#endif
