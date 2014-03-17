/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:25:05 by pferry            #+#    #+#             */
/*   Updated: 2014/03/17 21:08:22 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabnew(int len)
{
	char	**new;

	new = (char **)malloc(sizeof(char *) * (len + 1));
	if (new == NULL)
		return (NULL);
	return (new);
}
