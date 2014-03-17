/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 01:18:45 by pferry            #+#    #+#             */
/*   Updated: 2014/03/17 21:02:37 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_tn(int c)
{
	int		res;

	res = 1;
	while (c > 0)
	{
		res *= 10;
		c--;
	}
	return (res);
}

static int		ft_ab(int n)
{
	n = (n > 0) ? n : -n;
	return (n);
}

char			*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		len;

	i = 0;
	len = ft_intlen(n);
	result = (char*)malloc(sizeof(char) * (len + 2));
	if (result == NULL)
		return (NULL);
	if (n == -2147483648)
		return ("-2147483648");
	if (n < 0)
	{
		result[i] = '-';
		len++;
		i++;
	}
	while (i < len)
	{
		result[i] = ft_ab(n / (ft_tn(len - 1 - i))) + 48;
		n = ft_ab(n) - ((ft_ab(n) / (ft_tn(len - 1 - i))) * ft_tn(len - 1 - i));
		i++;
	}
	result[i] = '\0';
	return (result);
}
