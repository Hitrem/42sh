/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 11:26:01 by pferry            #+#    #+#             */
/*   Updated: 2014/03/17 21:00:48 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int nbr)
{
	int		size;

	size = 0;
	if (nbr == -2147483648)
		return (11);
	else if (nbr < 0)
	{
		size++;
		nbr *= -1;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size + 1);
}

int		ft_u_intlen(unsigned int nbr)
{
	int		size;

	size = 0;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size + 1);
}

int		ft_octlen(unsigned int n)
{
	int		size;

	size = 0;
	while (n > 7)
	{
		n = n / 8;
		size++;
	}
	return (size + 1);
}

int		ft_hexlen(unsigned long n)
{
	int		size;

	size = 0;
	while (n > 15)
	{
		n = n / 16;
		size++;
	}
	return (size + 1);
}
