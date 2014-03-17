/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chardelete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 17:09:50 by pferry            #+#    #+#             */
/*   Updated: 2014/03/04 17:22:51 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_chardelete(char *line, int i)
{
	char	*new;
	int		j;

	j = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(line));
	if (new == NULL)
		return (NULL);
	while (j < i - 1)
	{
		new[j] = line[j];
		j++;
	}
	while (line[j + 1])
	{
		new[j] = line[j + 1];
		j++;
	}
	new[j] = '\0';
	free(line);
	return (new);
}
