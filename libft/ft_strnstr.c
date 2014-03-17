/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:33:01 by pferry            #+#    #+#             */
/*   Updated: 2013/11/25 23:30:31 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <string.h>

char	*ft_strnstr(char const *s1, char const *s2, size_t n)
{
	unsigned int	i1;
	unsigned int	i2;
	unsigned int	max;

	i1 = 0;
	i2 = 0;
	max = 0;
	if (s2[i2] == '\0')
		return ((char*)s1);
	while (i1 < n && s1[i1])
	{
		i2 = 0;
		while (s2[i2] == s1[i1 + i2] && s2[i2] && (i1 + i2) < n)
		{
			i2++;
			max++;
		}
		if (s2[i2] == '\0')
			return ((char*)s1 + i1);
		i1++;
	}
	return (NULL);
}
