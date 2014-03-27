/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 22:43:31 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 07:29:47 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "list.h"

t_list			*init_element(void *value, t_list *next)
{
	t_list		*new;

	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = next;
	return (new);
}

t_list			*list_init(int nb_of_elts, void *first, ...)
{
	t_list		*new;
	t_list		*head;
	va_list		list;
	int			i;

	new = init_element(first, NULL);
	if (!new)
		return (NULL);
	head = new;
	va_start(list, first);
	i = 1;
	while (i < nb_of_elts)
	{
		new->next = init_element(va_arg(list, void *), NULL);
		new = new->next;
		i++;
	}
	return (head);
}

t_list			*list_search(t_list *list, void *value, int cmp(void *, void *))
{
	t_list		*tmp;

	tmp = list;
	while (tmp)
	{
		if (cmp(tmp->value, value))
			return (list);
		tmp = tmp->next;
	}
	return (NULL);
}

void			list_free(t_list *list, void free_fun (void *))
{
	t_list			*tmp;

	while (list)
	{
		tmp = list->next;
		free_fun(list->value);
		free(list);
		list = tmp;
	}
}
