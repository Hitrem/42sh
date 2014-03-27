/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 02:29:26 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 02:32:55 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_list		t_list;

struct						s_list
{
	void					*value;
	t_list					*next;
};

int							(*g_cmp_fun) (void *, void *);
void						(*g_free_fun) (void *);
t_list						*init_element(void *value, t_list *next);
t_list						*list_init(int nb_of_elts, void *first, ...);
t_list						*list_add(t_list *list, int index, void *value);
t_list						*list_append(t_list *list, void *value);
t_list						*list_search(t_list *list, void *value,
int cmp (void *, void *));
void						list_free(t_list *list, void free (void *));

#endif
