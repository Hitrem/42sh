/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:57:05 by pferry            #+#    #+#             */
/*   Updated: 2013/11/20 12:41:34 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int	count;

	count = 0;
	while (s1[count])
	{
		if (s2[count] == s1[count])
			count++;
		else
			return (0);
	}
	if (s2[count] == '\0')
		return (1);
	else
		return (0);
}
