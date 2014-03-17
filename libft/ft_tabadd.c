/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:56:49 by pferry            #+#    #+#             */
/*   Updated: 2014/01/24 15:56:50 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	**ft_tabadd(char **tab, char *str)
{
	char	**new;
	int		i;

	i = 0;
	new = (char **)malloc(sizeof(char *) * (ft_tablen(tab) + 2));
	if (new == NULL)
		return (NULL);
	while (tab[i])
	{
		new[i] = ft_strdup(tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	new[i] = ft_strdup(str);
	new[i + 1] = 0;
	return (new);
}
