/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:59:53 by pferry            #+#    #+#             */
/*   Updated: 2014/03/17 21:47:02 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <sys/stat.h>
# include <sys/wait.h>
# include <term.h>
# include <termcap.h>
# include <termios.h>
# include <sys/ioctl.h>
# include "/usr/include/termcap.h"

# define ESCAPE		27
# define SPACE		32
# define UP			4283163
# define LEFT		4479771
# define RIGHT		4414235
# define DOWN		4348699
# define RETURN		10
# define DELETE		127
# define BACKSPACE	2117294875

typedef struct		s_env
{
	t_list	*item;
	int		cury;
	int		li_max;
	int		co_max;
	int		curx;
	int		list_len;
	int		fd;
}					t_env;

t_env		env;

int		tputs_char(int c);
int		ft_listlen(t_list *item);
void	ft_error(char *name);
void	ft_env(char **env);
char	*ft_chardelete(char *line, int i);
char	*ft_linechange(char *buff, size_t i, char *line);


/*
** Shell1
*/

void	ft_get_info(char *file, int ret, int i);
void	ft_cmd(char **save, char **env);
void	search_cmd(char **cmd, char **env, size_t i);
char 	**ft_cd(char **save, char **env);
char	**ft_setenv(char **save, char **env, int add, int i);
char	**ft_unsetenv(char **save, char **env);

/*
** Shell2
*/

int		ft_is_spe_char(char c);
char	**ft_simple_cmd(char **save, char **env);
t_list	*ft_lexer(char *str, int i, int j);

/*
** Select
*/

void	ft_envinit(void);
void	ft_envreset(int sig);
void	ft_mysignal(int sigint);
void	ft_quit(int sigint);
void	ft_signal_init(void);	
char	*ft_keyboard(void);

#endif
