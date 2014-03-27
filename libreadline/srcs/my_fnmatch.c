/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fnmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 00:51:03 by sde-segu          #+#    #+#             */
/*   Updated: 2014/03/27 06:12:59 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_fnmatch.h"

int					interval(const char *pattern, const char *string)
{
	if ((*(pattern + 2) == '-') && (*(pattern + 3) == ']'))
		return (close_bracket(pattern + 1, string));
	if (*(pattern + 4) == ']')
	{
		if ((*string >= *(pattern + 1)) && (*string <= *(pattern + 3)))
			return (my_fnmatch(pattern + 5, string + 1));
		return (1);
	}
	if (*(pattern + 4) != ']')
	{
		if ((*string >= *(pattern + 1)) && (*string <= *(pattern + 3)))
		{
			while (*pattern != ']')
				pattern += 1;
			return (my_fnmatch(pattern + 1, string + 1));
		}
		return (bracket(pattern + 3, string));
	}
	return (1);
}

int					close_bracket(const char *pattern, const char *string)
{
	const char *tmp = NULL;

	tmp = pattern;
	while ((*tmp != '\0') && (*tmp != ']'))
		tmp += 1;
	if (*tmp == '\0')
	{
		if (*string == *pattern)
			return (my_fnmatch(pattern + 1, string + 1));
		return (my_fnmatch(pattern + 1, string));
	}
	if (*pattern == '[')
		if ((*(pattern + 9) == ']') || (*(pattern + 10) == ']'))
			return (bonus(pattern + 3, string));
	return (star(pattern, string, 2));
}

int					bracket(const char *pattern, const char *string)
{
	if (*(pattern + 2) == '-')
		return (interval(pattern, string));
	if (*(pattern + 1) != ']')
		return (close_bracket(pattern, string));
	else if (*(pattern + 1) == ']')
	{
		pattern += 1;
		if (*string == *pattern)
		{
			pattern += 1;
			while (*pattern != ']')
				pattern += 1;
			return (my_fnmatch(pattern + 1, string + 1));
		}
		return (close_bracket(pattern + 1, string));
	}
	return (1);
}

int					star(const char *pattern, const char *string, int i)
{
	if (i == 1)
	{
		if (*string == '\0')
			return (my_fnmatch(pattern + 1, string));
		if ((my_fnmatch(pattern + 1, string) == 0)
			|| (my_fnmatch(pattern, string + 1) == 0))
			return (0);
	}
	if (i == 2)
	{
		while (*pattern != ']')
		{
			if (*string == *pattern)
			{
				while (*pattern != ']')
					pattern += 1;
				return (my_fnmatch(pattern + 1, string + 1));
			}
			if (*(pattern + 2) == '-')
				return (interval(pattern, string));
			pattern += 1;
		}
	}
	return (1);
}

int					my_fnmatch(const char *pattern, const char *string)
{
	if ((pattern == NULL) || (string == NULL))
		return (0);
	if ((*pattern == '[') && (*(pattern + 1) == '!'))
		return (!(bracket(pattern + 1, string)));
	if (*pattern == '[')
		return (bracket(pattern, string));
	if (*pattern == '\\')
		return (backslash(pattern, string));
	else if (*pattern == '?')
	{
		if (*string == '\0')
			return (1);
		return (my_fnmatch(pattern + 1, string + 1));
	}
	else if (*pattern == '*')
		return (star(pattern, string, 1));
	else if (*pattern == '[')
		return (bracket(pattern, string));
	else if (*string == *pattern)
	{
		if (*string == '\0')
			return (0);
		return (my_fnmatch(pattern + 1, string + 1));
	}
	return (1);
}
