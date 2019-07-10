/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 12:27:44 by omaltsev          #+#    #+#             */
/*   Updated: 2019/03/16 15:25:40 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*choose_type2(t_options *opt, t_modifiers *mod, va_list ap, char type)
{
	if (type == 'X' && (opt->capital_let = 1))
		return (ft_base(opt, ap, mod, 16));
	if (type == 'u')
		return (ft_base(opt, ap, mod, 10));
	if (type == 'U' && (mod->l = 1))
		return (ft_base(opt, ap, mod, 10));
	if (type == 'p' && (opt->hash = 1))
	{
		mod->l = 1;
		return (ft_point(opt, ap, mod));
	}
	if (type == 'f')
		return (ft_float(opt, mod, ap));
	if (type == 'F' && (mod->up_l = 1))
		return (ft_float(opt, mod, ap));
	return (ft_strdup(""));
}

char	*find_params(char *str, t_options *opt, t_modifiers *mod, va_list ap)
{
	while (ft_strchr("+-#0* 123456789.hlLzj", *str) != NULL && *str != '\0')
	{
		if (ft_strchr("#+- ", *str))
			str = flags(opt, str);
		else if ((*str >= '0' && *str <= '9') || *str == ' ')
			str = width(opt, &*str);
		else if (*str == '*')
			str = asterisk(opt, &*str, ap);
		else if (*str == '.')
			str = accuracy(opt, &*str, ap);
		else if (ft_strchr("hlzjL", *str))
			str = modifiers(mod, &*str);
		else
			str++;
	}
	return (str);
}
