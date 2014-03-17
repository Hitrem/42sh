/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:15:37 by pferry            #+#    #+#             */
/*   Updated: 2014/03/17 21:06:52 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	int		index;
	char	*str2;

	index = 0;
	str2 = (char *)malloc(sizeof(char) * (ft_strlen(str1) + 1));
	while (str1[index])
	{
		str2[index] = str1[index];
		index++;
	}
	str2[index] = str1[index];
	return (str2);
}
