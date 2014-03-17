/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raudiber <raudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 20:15:32 by pferry            #+#    #+#             */
/*   Updated: 2014/03/17 21:05:33 by raudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cut(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '%' && s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

static int	ft_putoption(const char **str, char c, va_list ap)
{
	int	tmp;
	int	i;

	i = 0;
	if (**str == c)
	{
		while (**str == c)
			*str = *str + 1;
		if (*str[i] == 'd')
		{
			tmp = va_arg(ap, int);
			if (tmp >= 0)
				i += ft_putchar2(c);
			ft_putnbr(tmp);
			i += ft_intlen(tmp);
		}
	}
	return (i);
}

static int	ft_putwhat2(char c, va_list ap)
{
	int				i;
	unsigned long	tmp;

	i = 0;
	tmp = 0;
	if (c == 'o')
	{
		tmp = va_arg(ap, unsigned int);
		i += ft_octlen(tmp);
		ft_putoct(tmp);
	}
	else if (c == 'x')
	{
		tmp = va_arg(ap, unsigned long);
		i += ft_hexlen(tmp);
		ft_puthex(tmp);
	}
	else if (c == 'u')
	{
		tmp = va_arg(ap, unsigned int);
		i += ft_u_intlen(tmp);
		ft_put_u_nbr(tmp);
	}
	return (i);
}

static int	ft_putwhat(char c, va_list ap)
{
	int				i;
	unsigned long	tmp;

	i = ft_putwhat2(c, ap);
	tmp = 0;
	if (c == 's')
		i += ft_putstr2(va_arg(ap, char *));
	else if (c == 'p')
		i += ft_putmem(va_arg(ap, unsigned long));
	else if (c == 'd' || c == 'i')
	{
		tmp = (va_arg(ap, int));
		i += ft_intlen(tmp);
		ft_putnbr(tmp);
	}
	else if (c == 'c')
		i += ft_putchar2(va_arg(ap, int));
	else if (i == 0)
		i += ft_putchar2(c);
	return (i);
}

int			ft_printf(const char *str, ...)
{
	int		i;
	va_list ap;

	i = 0;
	va_start(ap, str);
	if (str == NULL)
		return (ft_putstr2("(null)"));
	while (*str != '\0')
	{
		i += ft_cut(str);
		if ((str = ft_strchr(str, '%')) == NULL)
			return (i);
		if (*str != '\0')
			str++;
		if (*str == ' ' || *str == '+' || ft_isdigit(*str) == 1)
			i += ft_putoption(&str, *str, ap);
		else
			i += ft_putwhat(*str, ap);
		str = str + 1;
	}
	va_end(ap);
	return (i);
}
