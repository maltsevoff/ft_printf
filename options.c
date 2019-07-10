/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:22:32 by omaltsev          #+#    #+#             */
/*   Updated: 2019/03/15 16:35:25 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*flags(t_options *opt, char *str)
{
	*str == '#' ? opt->hash = 1 : 0;
	*str == '+' ? opt->showsign = 1 : 0;
	*str == '-' ? opt->min = 1 : 0;
	*str == ' ' ? opt->spc = 1 : 0;
	str++;
	return (&*str);
}

char		*asterisk(t_options *opt, char *str, va_list ap)
{
	int		num;

	opt->width_flag = 1;
	num = va_arg(ap, int);
	if (num < 0)
	{
		opt->min = 1;
		opt->width = ABS(num);
	}
	else
		opt->width = num;
	str++;
	return (&*str);
}

char		*accuracy(t_options *opt, char *str, va_list ap)
{
	int		tmp;

	str++;
	opt->acc_flag = 1;
	if (*str == '*')
	{
		tmp = va_arg(ap, int);
		if (tmp < 0)
			opt->acc_flag = 0;
		else
			opt->acc = tmp;
	}
	else
		opt->acc = ft_atoi(&*str);
	while ((*str >= '0' && *str <= '9') || *str == '*')
		str++;
	return (&*str);
}

char		*width(t_options *opt, char *str)
{
	if (*str == '0')
	{
		opt->zero = 1;
		str++;
	}
	if (*str >= '1' && *str <= '9')
	{
		opt->width = ft_atoi(&*str);
		opt->width_flag = 1;
	}
	while (*str >= '0' && *str <= '9')
		str++;
	return (&*str);
}

char		*modifiers(t_modifiers *mod, char *str)
{
	if (*str == 'h' && *(str + 1) != 'h' && (str += 1))
		mod->h = 1;
	else if (*str == 'h' && *(str + 1) == 'h' && (str += 2))
		mod->hh = 1;
	else if (*str == 'l' && *(str + 1) != 'l' && (str += 1))
		mod->l = 1;
	else if (*str == 'l' && *(str + 1) == 'l' && (str += 2))
		mod->ll = 1;
	else if (*str == 'z' && (str += 1))
		mod->z = 1;
	else if (*str == 'j' && (str += 1))
		mod->j = 1;
	else if (*str == 'L' && (str += 1))
		mod->up_l = 1;
	return (&*str);
}
