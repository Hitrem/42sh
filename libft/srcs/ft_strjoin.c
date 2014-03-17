/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:45:03 by pferry            #+#    #+#             */
/*   Updated: 2014/03/17 21:07:11 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*news;
	int		i1;
	int		i2;

	i1 = 0;
	i2 = 0;
	news = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (news == NULL)
		return (NULL);
	while (s1[i1])
	{
		news[i1] = s1[i1];
		i1++;
	}
	while (s2[i2])
	{
		news[i1] = s2[i2];
		i1++;
		i2++;
	}
	news[i1] = '\0';
	return (news);
}
