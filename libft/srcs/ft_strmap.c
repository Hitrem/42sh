/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:26:23 by pferry            #+#    #+#             */
/*   Updated: 2014/03/17 21:07:23 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		index;
	char	*newchar;

	index = 0;
	newchar = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[index])
	{
		newchar[index] = f(s[index]);
		index++;
	}
	return (newchar);
}
