/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 13:13:16 by pferry            #+#    #+#             */
/*   Updated: 2014/03/17 20:19:54 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*ft_keyboard(void)
{
	char	buff[5];
	char	*line;
	size_t	i;

	i = 0;
	if (!(line = ft_strnew(1)))
		ft_error("malloc.");
	while (42)
	{
		ft_bzero(buff, 5);
		read(0, buff, 5);
		if (buff[0] == '\n')
		{
			ft_linechange(NULL, i, line);
			return (line);
		}
		if (*(int *)buff > 31 && *(int *)buff < 127)
		{
			line = ft_charjoin(line, buff[0], i);
			ft_putchar(buff[0]);
			i++;
		}
		else if (*(int *)buff == 9)
		{
			line = ft_charjoin(line, 9, i);
			ft_putchar(9);
			i++;
		}
		else if (*(int *)buff == 127 && i > 0) //delete <-
		{
			if (line[i] != '\t')
			{
				line = ft_chardelete(line, i);
				ft_putchar('\b');
				tputs(tgetstr("dc", NULL), 1, tputs_char);
				i--;
			}
			else
			{
				line = ft_chardelete(line, i);
				ft_putchar('\b');
				tputs(tgetstr("dc", NULL), 1, tputs_char);
				ft_putchar('\b');
				tputs(tgetstr("dc", NULL), 1, tputs_char);
				ft_putchar('\b');
				tputs(tgetstr("dc", NULL), 1, tputs_char);
				ft_putchar('\b');
				tputs(tgetstr("dc", NULL), 1, tputs_char);
			}


		}
		else if (*(int *)buff == 2117294875 && i < ft_strlen(line)) //delete ->
		{
			line = ft_chardelete(line, i + 1);
			tputs(tgetstr("dc", NULL), 1, tputs_char);
		}
		else if (*(int *)buff == 4414235 && i < ft_strlen(line)) // RIGHT
		{
			tputs(tgetstr("nd", NULL), 1, tputs_char);
			i++;
		}
		else if (*(int *)buff == 4479771 && i > 0) // LEFT
		{
			tputs(tgetstr("le", NULL), 1, tputs_char);
			i--;
		}
		else if (*(int *)buff == UP || *(int *)buff == DOWN)
			line = ft_linechange(buff, i, NULL);
//		else
//			ft_putnbr(*(int *)buff);
	}
}