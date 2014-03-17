/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:20:18 by pferry            #+#    #+#             */
/*   Updated: 2013/11/27 20:53:08 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*cp1;
	unsigned char	*cp2;

	i = 0;
	cp1 = (unsigned char*)s1;
	cp2 = (unsigned char*)s2;
	while (i < n)
	{
		cp1[i] = cp2[i];
		i++;
	}
	return (s1);
}
