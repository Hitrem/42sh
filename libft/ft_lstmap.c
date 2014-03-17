/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 15:40:46 by pferry            #+#    #+#             */
/*   Updated: 2013/11/30 16:27:42 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *list, t_list *(f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	new = (t_list*)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	tmp = new;
	while (list->next)
	{
		new = f(list);
		new = new->next;
		list = list->next;
	}
	new = f(list);
	return (tmp);
}
