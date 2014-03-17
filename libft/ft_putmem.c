/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 14:48:06 by pferry            #+#    #+#             */
/*   Updated: 2013/12/21 17:48:14 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_putmem(unsigned long ptr)
{
	int	i;

	i = 2;
	ft_putstr("0x");
	ft_puthex(ptr);
	i += ft_hexlen(ptr);
	return (i);
}
