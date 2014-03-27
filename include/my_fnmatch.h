/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fnmatch.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:33:55 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 06:12:58 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_FNMATCH_H
# define MY_FNMATCH_H

# include <stdlib.h>

int				my_fnmatch(const char *pattern, const char *string);
int				bracket(const char *pattern, const char *string);
int				close_bracket(const char *pattern, const char *string);
int				star(const char *pattern, const char *string, int i);
int				interval(const char *pattern, const char *string);
int				g_p_c(const char *pattern, const char *string, int i);
int				l_u_b_s_p(const char *pattern, const char *string, int i);
int				a_d_x(const char *pattern, const char *string, int i);
int				bonus(const char *pattern, const char *string);
int				backslash(const char *pattern, const char *string);

#endif
