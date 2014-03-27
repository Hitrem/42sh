/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 22:53:46 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/26 23:01:13 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "my_string.h"

int			my_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*my_strcpy(char *src)
{
	int			len;
	char		*cpy;
	int			i;

	len = my_strlen(src);
	cpy = (char*)malloc(sizeof(char) * len + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[len] = '\0';
	return (cpy);
}

char		*itoa_neg(int i)
{
	char		*pos;
	char		*neg;
	int			j;

	pos = my_itoa(i);
	neg = (char*)malloc(sizeof(char) * 12);
	neg[0] = '-';
	j = 0;
	while (pos[j])
	{
		neg[j + 1] = pos[j];
		j++;
	}
	neg[j + 1] = '\0';
	return (neg);
}

char		*my_itoa(int i)
{
	char		*ret_itoa;
	int			pos;
	int			my_num;
	int			pow;
	int			tmp;

	if (i < 0)
		return (itoa_neg(-i));
	ret_itoa = (char*)malloc(sizeof(char) * 12);
	pos = 0;
	my_num = i + 1;
	pow = 1;
	while (pow * 10 <= i)
		pow *= 10;
	while (pow != 0)
	{
		tmp = 1;
		while (tmp * pow < my_num)
			++tmp;
		--tmp;
		ret_itoa[pos] = tmp + '0';
		pos++;
		my_num -= tmp * pow;
		pow /= 10;
	}
	ret_itoa[pos] = '\0';
	return (ret_itoa);
}
