/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 16:24:32 by pferry            #+#    #+#             */
/*   Updated: 2014/01/26 16:24:38 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	count;

	count = 0;
	while (s1[count] && s2[count] && count < n && s2[count] == s1[count])
	{
		count++;
	}
	if (count == n || s1[count] == s2[count])
		return (1);
	else
		return (0);
}
