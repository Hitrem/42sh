/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 21:27:44 by pferry            #+#    #+#             */
/*   Updated: 2014/03/17 21:07:15 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i1;
	unsigned int	i2;
	unsigned int	n;

	i1 = 0;
	i2 = 0;
	n = ft_strlen(dst);
	if (n > size)
		n = size;
	n += ft_strlen(src);
	while (dst[i1] && i1 < (size - 1))
		i1++;
	if ((i1 + 1) >= size)
		return (n);
	while (src[i2] && i1 < (size - 1))
	{
		dst[i1] = (char)src[i2];
		i1++;
		i2++;
	}
	dst[i1] = '\0';
	return (n);
}
