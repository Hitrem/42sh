/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferry <pferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:14:40 by pferry            #+#    #+#             */
/*   Updated: 2013/11/21 18:17:23 by pferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void(*f)(unsigned int, char *))
{
	unsigned int	index;

	index = 0;
	while (s[index])
	{
		f(index, s + index);
		index++;
	}
}
