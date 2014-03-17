/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 18:59:40 by pferry            #+#    #+#             */
/*   Updated: 2014/03/17 21:10:32 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cut_line(char const *str)
{
	int		index;

	index = 0;
	while (str[index] != '\n' && str[index] != '\0')
		index++;
	return (index);
}

int		ft_return_next_line(char **line, char **save)
{
	if (ft_strchr(*save, '\n') != NULL)
	{
		*line = ft_strnew(ft_strlen(*save));
		ft_strclr(*line);
		*line = ft_strncat(*line, *save, ft_cut_line(*save));
		*save = ft_strchr(*save, '\n') + 1;
		return (1);
	}
	return (0);
}

int		ft_loop(int fd, char **line, char **save)
{
	char			*buf;
	unsigned int	ret;

	buf = (char*)malloc(sizeof(char) * BUFF_SIZE);
	if (buf == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		*save = ft_strjoin(*save, buf);
		ft_strclr(buf);
		if (ft_return_next_line(line, save) == 1)
			return (1);
	}
	*save = ft_strjoin(*save, buf);
	free(buf);
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char		*save;

	if (!save)
	{
		save = ft_strnew(BUFF_SIZE);
		if (ft_loop(fd, line, &save) == 1)
			return (1);
		else if (ft_loop(fd, line, &save) == -1)
			return (-1);
		else
			return (0);
	}
	if (save && ft_return_next_line(line, &save) == 1)
		return (1);
	else if (ft_loop(fd, line, &save) == 1)
		return (1);
	else if (ft_loop(fd, line, &save) == -1)
		return (-1);
	else
	{
		ft_strclr(*line);
		*line = ft_strncat(*line, save, ft_cut_line(save));
	}
	return (0);
}
