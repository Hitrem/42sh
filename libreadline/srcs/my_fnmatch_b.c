/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fnmatch_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:45:35 by jwoodrow          #+#    #+#             */
/*   Updated: 2014/03/27 06:12:58 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_fnmatch.h"

int					g_p_c(const char *pattern, const char *string, int i)
{
	if (i == 1)
		if ((*(pattern + 3) == 'p') && (*(pattern + 4) == 'h'))
			if (((*string >= 'A') && (*string <= 'Z'))
				|| ((*string >= 'a') && (*string <= 'z'))
					|| ((*string >= '0') && (*string <= '9'))
						|| ((*string >= '!') && (*string <= '/'))
							|| ((*string >= '[') && (*string <= '`'))
								|| ((*string >= '{') && (*string <= '~')))
				return (my_fnmatch(pattern + 8, string + 1));
	if (i == 2)
		if ((*(pattern + 3) == 'n') && (*(pattern + 4) == 't'))
			if (((*string >= 'A') && (*string <= 'Z'))
				|| ((*string >= 'a') && (*string <= 'z'))
					|| ((*string >= '0') && (*string <= '9'))
						|| ((*string >= '!') && (*string <= '/'))
							|| ((*string >= '[') && (*string <= '`'))
								|| ((*string >= '{') && (*string <= '~')))
				return (my_fnmatch(pattern + 8, string + 1));
	if (i == 3)
		if ((*(pattern + 3) <= 'r') && (*(pattern + 4) == 'l'))
			if (((*string >= 0) && (*string <= 32)) || (*string == 127))
				return (my_fnmatch(pattern + 8, string + 1));
	return (1);
}

int					l_u_b_s_p(const char *pattern, const char *string, int i)
{
	if (i == 1)
		if ((*(pattern + 3) == 'e') && (*(pattern + 4) == 'r'))
			if ((*string >= 'a') && (*string <= 'z'))
				return (my_fnmatch(pattern + 8, string + 1));
	if (i == 2)
		if ((*(pattern + 3) == 'e') && (*(pattern + 4) == 'r'))
			if ((*string >= 'A') && (*string <= 'Z'))
				return (my_fnmatch(pattern + 8, string + 1));
	if (i == 3)
		if ((*(pattern + 3) == 'n') && (*(pattern + 4) == 'k'))
			if (*string == ' ')
				return (my_fnmatch(pattern + 8, string + 1));
	if (i == 4)
		if ((*(pattern + 3) == 'c') && (*(pattern + 4) == 'e'))
			if ((*string == ' ') || (*string == '\n')
				|| (*string == '\f') || (*string == '\r'))
				return (my_fnmatch(pattern + 8, string + 1));
	if (i == 5)
		if ((*(pattern + 3) == 'c') && (*(pattern + 4) == 't'))
			if (((*string >= '!') && (*string <= '/'))
				|| ((*string >= '[') && (*string <= '`'))
					|| ((*string >= '{') && (*string <= '~')))
				return (my_fnmatch(pattern + 8, string + 1));
	return (1);
}

int					a_d_x(const char *pattern, const char *string, int i)
{
	if (i == 1)
		if ((*(pattern + 3) == 'h') && (*(pattern + 4) == 'a'))
			if (((*string >= 'A') && (*string <= 'Z'))
				|| ((*string >= 'a') && (*string <= 'z')))
				return (my_fnmatch(pattern + 8, string + 1));
	if (i == 2)
		if ((*(pattern + 3) == 'u') && (*(pattern + 4) == 'm'))
			if (((*string >= 'A') && (*string <= 'Z'))
				|| ((*string >= 'a') && (*string <= 'z'))
					|| ((*string >= '0') && (*string <= '9')))
				return (my_fnmatch(pattern + 8, string + 1));
	if (i == 3)
		if ((*(pattern + 3) == 'i') && (*(pattern + 4) == 't'))
			if ((*string >= '0') && (*string <= '9'))
				return (my_fnmatch(pattern + 8, string + 1));
	if (i == 4)
		if ((*(pattern + 3) == 'g') && (*(pattern + 4) == 'i')
			&& (*(pattern + 5) == 't'))
			if (((*string >= '0') && (*string <= '9'))
				|| ((*string >= 'A') && (*string <= 'F'))
					|| ((*string >= 'a') && (*string <= 'f')))
				return (my_fnmatch(pattern + 9, string + 1));
	return (1);
}

int					bonus(const char *pattern, const char *string)
{
	if ((*pattern == 'a') && (*(pattern + 1) == 'l') && (*(pattern + 2) == 'p'))
		return (a_d_x(pattern, string, 1));
	if ((*pattern == 'a') && (*(pattern + 1) == 'l') && (*(pattern + 2) == 'n'))
		return (a_d_x(pattern, string, 2));
	if ((*pattern == 'd') && (*(pattern + 1) == 'i') && (*(pattern + 2) == 'g'))
		return (a_d_x(pattern, string, 3));
	if ((*pattern == 'x') && (*(pattern + 1) == 'd') && (*(pattern + 2) == 'i'))
		return (a_d_x(pattern, string, 4));
	if ((*pattern == 'l') && (*(pattern + 1) == 'o') && (*(pattern + 2) == 'w'))
		return (l_u_b_s_p(pattern, string, 1));
	if ((*pattern == 'u') && (*(pattern + 1) == 'p') && (*(pattern + 2) == 'p'))
		return (l_u_b_s_p(pattern, string, 2));
	if ((*pattern == 'b') && (*(pattern + 1) == 'l') && (*(pattern + 2) == 'a'))
		return (l_u_b_s_p(pattern, string, 3));
	if ((*pattern == 's') && (*(pattern + 1) == 'p') && (*(pattern + 2) == 'a'))
		return (l_u_b_s_p(pattern, string, 4));
	if ((*pattern == 'p') && (*(pattern + 1) == 'u') && (*(pattern + 2) == 'n'))
		return (l_u_b_s_p(pattern, string, 5));
	if ((*pattern == 'g') && (*(pattern + 1) == 'r') && (*(pattern + 2) == 'a'))
		return (g_p_c(pattern, string, 1));
	if ((*pattern == 'p') && (*(pattern + 1) == 'r') && (*(pattern + 2) == 'i'))
		return (g_p_c(pattern, string, 2));
	if ((*pattern == 'c') && (*(pattern + 1) == 'n') && (*(pattern + 2) == 't'))
		return (g_p_c(pattern, string, 3));
	return (1);
}

int					backslash(const char *pattern, const char *string)
{
	if ((*(pattern + 1) != '*') && (*(pattern + 1) != '?')
		&& (*(pattern + 1) != '[') && (*(pattern + 1) != '\\'))
	{
		if (*pattern == *string)
			return (my_fnmatch(pattern + 1, string + 1));
		return (1);
	}
	else
	{
		if (*(pattern + 1) == *string)
			return (my_fnmatch(pattern + 2, string + 1));
		return (1);
	}
}
