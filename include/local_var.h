/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_var.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:33:06 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 06:12:39 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOCAL_VAR_H
# define LOCAL_VAR_H

# include "exec.h"

char			*get_var_name(char *str);
char			*get_var_value(char *str);
char			*reload_prompt(char *str);
char			*check_var(char *str);
t_var			*change_value(char *name, char *value, t_var *g_var);
char			*substitute_char2(char *res, char *value, char *str, size_t i);
char			*substitute_char(char *res, char *value, char *str, size_t i);
char			*substitute(char *str);

#endif
