/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 00:17:51 by pferry            #+#    #+#             */
/*   Updated: 2014/03/17 21:07:55 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_isword(char *s, char c, int i)
{
	int		i2;
	char	*cpy;

	i2 = 0;
	cpy = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (cpy == NULL)
		return (NULL);
	while (s[i] != c && s[i])
	{
		cpy[i2] = (char)s[i];
		i++;
		i2++;
	}
	cpy[i2] = '\0';
	return (cpy);
}


static int		ft_isbadchar(char const *s, char c, int i)
{
	while (s[i] == c && s[i])
	{
		i++;
	}
	return (i);
}

static int		ft_isgoodchar(char const *s, char c, int i)
{
	while (s[i] != c && s[i])
	{
		i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		word;
	char	**split;

	i = 0;
	word = 0;
	split = (char**)malloc(sizeof(char*) * (ft_strlen(s) + 1));
	if (split == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i = ft_isbadchar(s, c, i);
		else if (s[i] != c)
		{
			split[word] = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
			split[word] = ft_isword((char*)s, c, i);
			i = ft_isgoodchar(s, c, i);
			word++;
		}
	}
	split[word + 1] = '\0';
	return (split);
}
