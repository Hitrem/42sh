/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:23:04 by pferry            #+#    #+#             */
/*   Updated: 2014/03/27 03:17:01 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOURCE_H
# define SOURCE_H

# include "exec.h"

int		parse_source(char *path);
int		my_source(t_ast *node);

#endif
