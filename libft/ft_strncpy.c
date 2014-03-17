/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:35:27 by pferry            #+#    #+#             */
/*   Updated: 2013/12/04 18:32:35 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

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
