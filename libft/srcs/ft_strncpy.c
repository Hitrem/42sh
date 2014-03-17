/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:35:27 by pferry            #+#    #+#             */
/*   Updated: 2014/03/17 21:07:37 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned int	index;
	unsigned int	count;

	index = 0;
	count = n;
	while (src[index] && count > 0)
	{
		dest[index] = (char)src[index];
		index++;
		count--;
	}
	if (ft_strlen(src) < n)
	{
		while (dest[index])
		{
			dest[index] = 0;
			index++;
		}
	}
	return (dest);
}
