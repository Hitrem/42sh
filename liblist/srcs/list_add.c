/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 22:50:26 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/26 22:52:40 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

t_list *list_add(t_list *list, int index, void *value)
{
	t_list		*head;
	t_list		*prev;
	int			i;
	t_list		*new;

	if (!list)
		return (list_init(1, value));
	if (index == 0)
		return (init_element(value, list));
	head = list;
	prev = list;
	i = 0;
	while (i < index && list)
	{
		prev = list;
		list = list->next;
		i++;
	}
	new = init_element(value, NULL);
	prev->next = new;
	new->next = list;
	return (head);
}

t_list *list_append(t_list *list, void *value)
{
	t_list *head;

	if (!list)
		return (list_init(1, value));
	head = list;
	while (list->next)
		list = list->next;
	list->next = init_element(value, NULL);
	return (head);
}
