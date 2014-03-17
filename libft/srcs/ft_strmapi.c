/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:04:40 by pferry            #+#    #+#             */
/*   Updated: 2014/03/17 21:07:27 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*newchar;

	index = 0;
	newchar = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[index])
	{
		newchar[index] = f(index, s[index]);
		index++;
	}
	return (newchar);
}
