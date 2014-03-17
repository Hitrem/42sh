/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 20:00:49 by pferry            #+#    #+#             */
/*   Updated: 2013/12/01 17:24:09 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char			*c1;
	char			*c2;
	unsigned int	index;

	c1 = (char*)s1;
	c2 = (char*)s2;
	index = 0;
	while (c2[index] && index < n)
	{
		if (c2[index] == c)
		{
			c1[index] = c2[index];
			index++;
			return ((char*)c1 + index);
		}
		c1[index] = c2[index];
		index++;
	}
	return (NULL);
}
