/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 00:50:43 by sde-segu          #+#    #+#             */
/*   Updated: 2014/03/27 06:12:41 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <libgen.h>
#include <unistd.h>
#include "local_var.h"
#include "exec.h"
#include "my_fnmatch.h"

char			*substitute_char3(char *res, char *str, size_t i)
{
	size_t	index;

	index = 0;
	if (str[i] == '\\' || str[i] == '$')
	{
		//
		index = strlen(res);
		res[index] = (str[i] == '$') ? 36 : 92;
		res[index + 1] = 0;
	}
	else
	{
		//
		index = strlen(res);
		res[index] = '\\';
		res[index + 1] = str[i];
		res[index + 2] = 0;
	}
	return (res);
}

char			*substitute_char2(char *res, char *value, char *str, size_t i)
{
	size_t		index;

	index = 0;
	if (str[i] == 'n' || str[i] == 'r')
	{
		//
		index = strlen(res);
		res[index] = (str[i] == 'n') ? 10 : 13;
		res[index + 1] = 0;
	}
	else if (str[i] == 's')
	{
		value = basename(getenv("SHELL"));
		//
		res = strcat(res, value);
	}
	else if (str[i] == 'w' || str[i] == 'W')
	{
		value = (str[i] == 'w') ? getenv("PWD") : basename(getenv("PWD"));
		//
		res = strcat(res, value);
	}
	else
		res = substitute_char3(res, str, i);
	return (res);
}

char			*substitute_char(char *res, char *value, char *str, size_t i)
{
	time_t		now;

	if (str[i] == 'd')
	{
		time(&now);
		value = ctime(&now);
		//
		res = strncat(res, value, 10);
	}
	else if (str[i] == 'h' || str[i] == 'H')
	{
		value = "freebsd";
		//
		res = strcat(res, value);
	}
	else if (str[i] == 'u')
	{
		value = getenv("USER");
		//
		res = strcat(res, value);
	}
	else
		res = substitute_char2(res, value, str, i);
	return (res);
}

char			*substitute(char *str)
{
	size_t		i;
	char		*value;
	char		*res;
	size_t		index;

	value = NULL;
	res = malloc(sizeof(char *) * 256);
	index = 0;
	res[0] = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\\' && str[++i] != '\0')
			res = substitute_char(res, value, str, i);
		else
		{
			//
			index = strlen(res);
			res[index] = str[i];
			res[index + 1] = 0;
		}
		i++;
	}
	return (res);
}

char			*check_var(char *str)
{
	char *var_name;
	char *var_val;
	char *new_var_val;

	var_name = NULL;
	var_val = NULL;
	if (my_fnmatch("*=*", str))
		return ("");
	else
	{
		if (find_var((var_name = get_var_name(str)), g_var) != NULL)
		{
			var_val = get_var_value(str);
			if (strcmp(var_val, ""))
			{
				new_var_val = substitute(var_val);
				g_var = change_value(var_name, var_val, g_var);
				free(var_name);
				return (new_var_val);
			}
			free(var_val);
		}
		free(var_name);
	}
	return ("");
}
