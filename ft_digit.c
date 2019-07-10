/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 17:50:47 by omaltsev          #+#    #+#             */
/*   Updated: 2019/03/15 16:33:09 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*work_sign(long long num, t_options *opt)
{
	char	*temp;

	if (num < 0)
	{
		opt->sign[0] = '-';
		opt->showsign = 1;
		temp = ft_itoa(ABS(num));
	}
	else
	{
		opt->sign[0] = '+';
		temp = ft_itoa(num);
	}
	if (opt->showsign == 1)
		opt->spc = 0;
	return (temp);
}

long long	work_modifier(va_list ap, t_modifiers *mod)
{
	if (mod->j == 1)
		return (va_arg(ap, intmax_t));
	if (mod->ll == 1)
		return (va_arg(ap, long long));
	if (mod->l == 1)
		return (va_arg(ap, long));
	if (mod->z == 1)
		return (va_arg(ap, size_t));
	if (mod->h == 1)
		return (va_arg(ap, short int));
	if (mod->hh == 1)
		return (va_arg(ap, char));
	return (va_arg(ap, int));
}

char		*ft_digit_acc(t_options *opt, char *str, int num_len)
{
	int		i;
	int		razn;
	char	*temp;
	char	*work;

	i = 0;
	temp = str;
	razn = opt->acc - num_len;
	work = ft_strnew(opt->acc);
	while (i < opt->acc)
	{
		if (i < razn)
			work[i] = '0';
		else
		{
			work[i] = *str;
			str++;
		}
		i++;
	}
	free(temp);
	return (work);
}

char		*ft_digit_width(t_options *opt, char *str, int num_len)
{
	int		tmp_len;
	char	*temp;
	char	*tmp;
	char	symbol;

	temp = str;
	symbol = (opt->zero == 0 || opt->acc_flag == 1) ? ' ' : '0';
	if (opt->min == 0)
		str = ft_d_width_1(num_len, opt, symbol, str);
	else
		str = ft_d_width_2(num_len, opt, symbol, str);
	if (temp != NULL)
		free(temp);
	if (opt->showsign == 1 && opt->acc_flag == 0 && opt->zero == 1 &&
		opt->min == 0)
		str[0] = opt->sign[0];
	if (opt->showsign == 0 && opt->spc == 1)
	{
		temp = str;
		str = ft_strjoin(" ", str);
		free(temp);
	}
	return (str);
}

char		*ft_digit(t_options *opt, t_modifiers *mod, va_list ap)
{
	int		num_len;
	char	*res;
	char	*tmp;

	res = work_sign(work_modifier(ap, mod), opt);
	num_len = ft_strlen(res);
	if (opt->acc_flag == 1)
		res = ft_main_acc(opt, num_len, res);
	num_len = ft_strlen(res);
	if (opt->width > num_len)
		res = ft_digit_width(opt, res, num_len);
	else
		opt->width_flag = 0;
	opt->acc_flag == 1 ? opt->acc_flag = 0 : 0;
	res = ft_digit_sign(opt, res);
	return (res);
}
