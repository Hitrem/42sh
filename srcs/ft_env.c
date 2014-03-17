/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 00:26:59 by pferry            #+#    #+#             */
/*   Updated: 2014/03/04 18:29:05 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int				tputs_char(int c)
{
	write(env.fd, &c, 1);
	return (1);
}

void			ft_envinit(void)
{
	char				buffer[2048];
	struct termios		term;

	if (tgetent(buffer, getenv("TERM")) < 1)
		ft_error("tgetent");
	if(tcgetattr(0, &term) == -1)
		ft_error("tcgetattr");
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_lflag |= ISIG;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &term);
	tputs(tgetstr("ti", NULL), 1, tputs_char);
	tputs(tgetstr("im", NULL), 1, tputs_char);
	env.fd = open("/dev/tty", O_RDWR);
	env.curx = 0;
	env.li_max = tgetnum("li");
	env.co_max = tgetnum("co");
	ft_signal_init();
}

void			ft_envreset(int sig)
{
	struct termios		term;

	if(tcgetattr(0, &term) == -1)
		ft_error("tcgetattr");
	tputs(tgetstr("ei", NULL), 1, tputs_char);
	tputs(tgetstr("te", NULL), 1, tputs_char);
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	term.c_lflag &= ~ISIG;
	close(env.fd);
	tcsetattr(0, 0, &term);
	if (sig == 0)
		exit(1);
}
