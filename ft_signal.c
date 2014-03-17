/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 19:15:36 by pferry            #+#    #+#             */
/*   Updated: 2014/02/05 19:25:24 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void			ft_mysignal(int sigint)
{
	char				buffer[2048];

	if (tgetent(buffer, getenv("TERM")) < 1)
		ft_error("tgetent");
	sigint = sigint;
	env.li_max = tgetnum("li");
	env.co_max = tgetnum("co");
	tputs(tgetstr("cl", NULL), 1, tputs_char);
}

void			ft_quit(int sigint)
{
	sigint = sigint;
	ft_envreset(0);
}

void			ft_signal_init(void)
{
	signal(SIGTSTP, &ft_quit);
	signal(SIGQUIT, &ft_quit);
	signal(SIGINT, &ft_quit);
	signal(SIGTERM, &ft_quit);
	signal(SIGHUP, &ft_quit);
	signal(SIGTTIN, &ft_quit);
	signal(SIGWINCH, &ft_mysignal);
}
