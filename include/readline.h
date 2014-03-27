/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:43:00 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 07:25:38 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

# include <unistd.h>
# include <stdlib.h>
# include <term.h>
# include <termcap.h>
# include <termios.h>
# include <sys/ioctl.h>
# include "/usr/include/termcap.h"

# include "history.h"

extern char				g_term_buffer[2048];
extern int				g_current_pos;
extern int				g_max_pos;
extern t_history		*g_current_cmd;

typedef struct			s_pid_loop
{
	int					is_in_loop;
	int					heredoc;
	int					pid;
	int					bang;
	int					return_value;
	int					is_in_file;
}						t_pid_loop;

typedef struct			s_termdata
{
	struct termios		saved_attr;
	char				*termtype;
}						t_termdata;

extern t_pid_loop		*g_pid_loop;
char					*readfile(char *filename, int exist);
int						readline(char **buff, char *filename, char eline);
int						readline2(char **buff, char *filename, char eline);
int						my_putchar (int ch);
int						add_char(char *str, int lent);
void					delete_char(void);
void					left(void);
void					right(void);
int						part_case(char *read_val);
int						return_line(char *read_val, int len);
void					signal_handler(int sig);
int						kill_proc(void);
void					reset_term(void);
void					init_terminal_data(void);
void					init_term(void);
int						termcap_example(char *read_val, int len);
int						part_case2(char *read_val);
void					fast_case(char *read_val, int g_current_pos,
int g_max_pos);
int						restore_term(int tty, int choice, char *read_val,
int len);

#endif
