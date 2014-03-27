/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shopt_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 23:22:43 by raudiber          #+#    #+#             */
/*   Updated: 2014/03/26 23:24:18 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "shopt.h"
#include "readline.h"

t_shpt	*init_shopt(void)
{
	g_shpt = NULL;
	g_shpt = add_shopt("xpg_echo", "off");
	g_shpt = add_shopt("sourcepath", "on");
	g_shpt = add_shopt("nullglob", "off");
	g_shpt = add_shopt("nocaseglob", "off");
	g_shpt = add_shopt("extglob", "off");
	g_shpt = add_shopt("expand_aliases", "off");
	g_shpt = add_shopt("dotglob", "off");
	g_shpt = add_shopt("ast_print", "off");
	return (g_shpt);
}

t_shpt	*add_shopt(char *name, char *on_off)
{
	t_shpt *new;

	new = NULL;
	new = malloc(sizeof(t_shpt));
	new->name = name;
	new->on_off = on_off;
	new->next = g_shpt;
	return (new);
}
