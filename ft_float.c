/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:49:09 by omaltsev          #+#    #+#             */
/*   Updated: 2019/03/15 16:33:25 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*ft_itoa_f(long double number)
{
	int			size;
	long double	point;
	long double	num;

	point = 1;
	size = 0;
	num = number;
	while (num > 1)
	{
		num /= 10;
		point *= 10;
		size++;
	}
	point /= 10;
	return (ft_itoa_f_2(size, num));
}

long double	round_n(t_options *opt, long double num)
{
	int			i;
	long long	tmp;

	i = -1;
	while (++i < opt->acc)
		num *= 10;
	tmp = (long long)num + 1;
	if (tmp % 2 == 0)
		num += 0.5;
	else
		num += 0.49;
	i = -1;
	while (++i < opt->acc)
		num /= 10;
	return (num);
}

char		*ftoa2(t_options *opt, long double number)
{
	int			length;
	int			tmp;
	long long	nm;
	char		*res;

	length = opt->acc;
	number = round_n(opt, number);
	res = ft_itoa_f(number);
	number = number - (long long)number;
	tmp = -1;
	while (++tmp < opt->acc)
		number *= 10;
	res = ft_strjoin(res, ".");
	res = ft_strjoin(res, ft_itoa_f(number));
	return (res);
}

char		*work_float(t_modifiers *mod, va_list ap, t_options *opt)
{
	double		number;
	__uint64_t	*b;

	if (mod->up_l == 1)
		number = va_arg(ap, double);
	else
		number = va_arg(ap, double);
	if (number * 2 == number && number != 0)
		return (mod->up_l == 1 ? ft_strdup("INF") : ft_strdup("inf"));
	if (number != number)
		return (mod->up_l == 1 ? ft_strdup("NAN") : ft_strdup("nan"));
	b = (__uint64_t *)&number;
	if ((*b >> 63) == 1)
	{
		opt->sign[0] = '-';
		opt->showsign = 1;
	}
	number = ABS(number);
	return (ftoa2(opt, number));
}

char		*ft_float(t_options *opt, t_modifiers *mod, va_list ap)
{
	int			str_len;
	char		*res;
	char		*tmp;

	opt->acc > 1000 ? opt->acc = 1000 : 0;
	opt->showsign == 1 ? opt->sign[0] = '+' : 0;
	if (opt->acc_flag == 0)
	{
		opt->acc = 6;
		opt->acc_flag = 1;
	}
	res = work_float(mod, ap, opt);
	str_len = ft_strlen(res);
	if (opt->showsign == 1)
		res = ft_strjoin(opt->sign, res);
	if (opt->showsign == 0 && opt->spc)
	{
		tmp = res;
		res = ft_strjoin(" ", res);
		free(tmp);
	}
	str_len = ft_strlen(res);
	if (opt->width > str_len)
		res = ft_string_width(opt, res, str_len);
	return (res);
}
