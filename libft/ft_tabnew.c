/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:25:05 by pferry            #+#    #+#             */
/*   Updated: 2014/01/31 13:48:34 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	**ft_tabnew(int len)
{
	char	**new;

	new = (char **)malloc(sizeof(char *) * (len + 1));
	if (new == NULL)
		return (NULL);
	return (new);
}
