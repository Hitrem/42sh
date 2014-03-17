/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 15:43:39 by pferry            #+#    #+#             */
/*   Updated: 2013/12/22 15:57:06 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/libft.h"

int		ft_putstr2(char *s)
{
	if (s == NULL)
		return (ft_putstr2("(null)"));
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int		ft_putchar2(char c)
{
	write(1, &c, 1);
	return (1);
}
