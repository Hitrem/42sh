/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 20:02:10 by pferry            #+#    #+#             */
/*   Updated: 2014/03/17 21:05:25 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned int			i;
	unsigned char			*cp1;
	unsigned const char		*cp2;
	unsigned char			*tmp;

	i = 0;
	cp1 = s1;
	cp2 = s2;
	tmp = (unsigned char*)malloc(sizeof(unsigned char) * (n + 1));
	while (i < n && cp2[i])
	{
		tmp[i] = cp2[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		cp1[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (s1);
}
