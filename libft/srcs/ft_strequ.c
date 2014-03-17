/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:57:05 by pferry            #+#    #+#             */
/*   Updated: 2014/03/17 21:06:58 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int	count;

	count = 0;
	while (s1[count])
	{
		if (s2[count] == s1[count])
			count++;
		else
			return (0);
	}
	if (s2[count] == '\0')
		return (1);
	else
		return (0);
}
