/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:17:35 by pferry            #+#    #+#             */
/*   Updated: 2013/11/26 18:29:54 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*news;
	unsigned int	index;

	news = (char*)malloc(sizeof(char) * (len + 1));
	if (news == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		news[index] = (char)s[start];
		index++;
		start++;
	}
	news[index] = '\0';
	return (news);
}
