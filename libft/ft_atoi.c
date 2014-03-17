/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 17:17:54 by pferry            #+#    #+#             */
/*   Updated: 2013/12/06 16:33:15 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_index(const char *str, int i)
{
	if ((str[i] == '\t' || str[i] == '\r' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == ' '))
	{
		return (1);
	}
	return (0);
}

int				ft_atoi(const char *str)
{
	int			result;
	int			index;
	int			minus;

	result = 0;
	index = 0;
	minus = 1;
	while (ft_index(str, index) != 0)
	{
		index++;
	}
	if (str[index] == '+')
		index++;
	else if (str[index] == '-')
	{
		minus = -1;
		index++;
	}
	while (ft_isdigit(str[index]) != 0)
	{
		result = (10 * result) + (str[index] - 48);
		index++;
	}
	return (result * minus);
}
