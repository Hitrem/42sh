/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 20:03:06 by pferry            #+#    #+#             */
/*   Updated: 2013/11/26 16:20:52 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*new;
	unsigned int	i;

	new = (char*)s;
	i = 0;
	while (new[i] && i < n)
	{
		if (new[i] == c)
			return ((char*)new + i);
		i++;
	}
	return (NULL);
}
