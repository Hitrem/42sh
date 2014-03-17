/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 16:16:25 by pferry            #+#    #+#             */
/*   Updated: 2014/01/28 16:16:36 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void    ft_lstaddend(t_list **lst, t_list *new)
{
    t_list   *tmp;
 
    tmp = *lst;
    if (*lst == NULL)
    {
        *lst = new;
    }
    else
    {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}
