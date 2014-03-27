/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompts.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:41:55 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 06:14:59 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPTS_H
# define PROMPTS_H

# include "parser.h"

int					ps1_loop(void);
char				*ps2_loop(char *head, char *eof, int tty);
void				free_prog(char *buff, t_ast *tree, int tty);
char				*ps2_loop(char *head, char *eof, int tty);
void				free_prog(char *buff, t_ast *tree, int tty);
void				init_prompt(void);
void				add_str(char **str1, char *str2);

#endif
