/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:56:28 by pferry            #+#    #+#             */
/*   Updated: 2014/03/17 21:08:05 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*snew;
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	end = ft_strlen(s) - 1;
	snew = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (snew == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == ',' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[end] == ' ' || s[end] == ',' || s[end] == '\n' || s[end] == '\t')
		end--;
	while (i < end)
	{
		snew[start] = s[i];
		start++;
		i++;
	}
	snew[start] = s[i];
	snew[start + 1] = '\0';
	return (snew);
}
