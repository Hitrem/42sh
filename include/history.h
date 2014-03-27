/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:17:55 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 05:26:22 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

typedef struct			s_history
{
	char				*last;
	int					exist;
	struct s_history	*previous;
	struct s_history	*next;
}						t_history;

t_history				*g_hist;
t_history				*g_current_hist;
t_history				*g_current_cmd;
char					*g_saved_line;

void					init_hist(void);
void					add_line_history(char *line, int exist);
void					free_hist(void);
void					init_from_file(void);
void					init_hist(void);

#endif
