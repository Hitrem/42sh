/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 13:28:06 by pferry            #+#    #+#             */
/*   Updated: 2014/03/17 21:02:10 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!*alst)
	{
		new->next = (*alst);
		*alst = new;
	}
	else
	{
		(*alst)->prev = new;
		new->next = (*alst);
		*alst = new;
	}

}
