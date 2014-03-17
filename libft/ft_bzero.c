/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:26:36 by pferry            #+#    #+#             */
/*   Updated: 2013/11/22 17:55:03 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *b, size_t len)
{
	unsigned int	count;
	char			*new;

	count = 0;
	new = b;
	while (count <= len)
	{
		new[count] = 0;
		count++;
	}
}
