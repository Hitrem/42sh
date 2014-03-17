/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 20:30:20 by pferry            #+#    #+#             */
/*   Updated: 2014/03/05 17:12:04 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

t_list	*ft_lstnew(char *content, size_t content_size)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	if (content == 0)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = (char*)malloc(sizeof(char) * ft_strlen(content) + 1);
		if (new->content == NULL)
			return (NULL);
		new->content = (char*)content;
		new->content_size = content_size;
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
