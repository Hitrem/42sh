/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 16:41:50 by pferry            #+#    #+#             */
/*   Updated: 2014/01/31 13:38:54 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	*ft_s_to_char(char *s, int i)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * 2);
	if (new == NULL)
		return (NULL);
	new[0] = s[i];
	new[1] = '\0';
	return (new);
}


static int	ft_lexer2(char *tmp, t_list **lst, char *str, int i)
{
	ft_lstaddend(lst, ft_lstnew(tmp, ft_strlen(tmp)));
	ft_lstaddend(lst, ft_lstnew(ft_s_to_char(str, i), 1));
	return (0);
}

t_list		*ft_lexer(char *str, int i, int j)
{
	t_list	*lst;
	char	*new;
	char	*tmp;

	lst = NULL;
	new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (new == NULL)
		ft_putendl_fd("Error in: lexer.", 2);
	tmp = ft_strtrim(str);
	if (ft_is_spe_char(tmp[ft_strlen(tmp) - 1]) == 0)
		ft_error("Lexer.");
	while (str[i])
	{
		if (ft_is_spe_char(str[i]) == 1)
			new[j++] = str[i];
		else
		{
			new[j] = '\0';
			j = ft_lexer2(ft_strtrim(new), &lst, str, i);
		}
		i++;
	}
	new[j] = '\0';
	tmp = ft_strtrim(new);
	ft_lstaddend(&lst, ft_lstnew(tmp, ft_strlen(tmp)));
	return (lst);
}
