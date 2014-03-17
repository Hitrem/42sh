/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:20:03 by pferry            #+#    #+#             */
/*   Updated: 2013/11/22 17:51:43 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	count;
	char			*new;

	new = b;
	count = 0;
	while (count < len)
	{
		new[count] = (unsigned char)c;
		count++;
	}
	return (new);
}
