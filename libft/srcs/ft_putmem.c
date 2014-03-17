/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 14:48:06 by pferry            #+#    #+#             */
/*   Updated: 2014/03/17 21:05:49 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putmem(unsigned long ptr)
{
	int	i;

	i = 2;
	ft_putstr("0x");
	ft_puthex(ptr);
	i += ft_hexlen(ptr);
	return (i);
}
