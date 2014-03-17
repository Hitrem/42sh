/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 18:30:42 by pferry            #+#    #+#             */
/*   Updated: 2014/03/17 21:05:54 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar('0' + n);
	}
}

void	ft_put_u_nbr(unsigned int nbr)
{
	if (nbr > 9)
	{
		ft_put_u_nbr(nbr / 10);
		ft_put_u_nbr(nbr % 10);
	}
	else
		ft_putchar('0' + nbr);
}

void	ft_putoct(unsigned int n)
{
	if (n > 7)
	{
		ft_putoct(n / 8);
		ft_putoct(n % 8);
	}
	else
		ft_putchar('0' + n);
}

void	ft_puthex(unsigned long n)
{
	if (n > 15)
	{
		ft_puthex(n / 16);
		ft_puthex(n % 16);
	}
	else if (n < 10)
	{
		ft_putchar('0' + n);
	}
	else
	{
		ft_putchar('a' + n - 10);
	}
}
