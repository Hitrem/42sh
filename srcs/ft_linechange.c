/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linechange.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:07:14 by pferry            #+#    #+#             */
/*   Updated: 2014/03/05 18:13:14 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_list	*lst;

char	*ft_linechange(char *buff, size_t i, char *line)
{
	char			*new;

	new = ft_strnew(1);
	if (!lst)
	{
		ft_putstr("ok");
		lst = NULL;
	}
	if (line == NULL)
	{
		if (*(int *)buff == UP && lst && lst->prev)
		{
		ft_putstr("OK");

			new = ft_strdup(lst->prev->content);
			ft_putstr(new);
		}
		else if (*(int *)buff == DOWN && lst && lst->next)
		{
			new = ft_strdup(lst->next->content);
			ft_putstr(new);
		}
	}
	else if (line[0] != '\0')
	{
		ft_putstr("oups");
		ft_lstadd(&lst, ft_lstnew(line, i));
	}
	return (new);
}
