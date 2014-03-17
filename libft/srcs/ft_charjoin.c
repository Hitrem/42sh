/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 16:18:09 by pferry            #+#    #+#             */
/*   Updated: 2014/03/17 21:02:31 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_charjoin(char *str, char c, int j)
{
	char 	*new;
	int		i;

	i = 0;
	new = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (new == NULL)
		return (NULL);
	while (i < j)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = c;
	while (str[i])
	{
		new[i + 1] = str[i];
		i++;
	}
	new[i + 1] = '\0';
	free(str);
	return (new);
}
