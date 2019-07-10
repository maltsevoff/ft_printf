/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:08:12 by omaltsev          #+#    #+#             */
/*   Updated: 2019/03/15 16:34:05 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long long	work_un_modifier(va_list ap, t_modifiers *mod)
{
	if (mod->ll == 1)
		return (va_arg(ap, unsigned long long));
	if (mod->l == 1)
		return (va_arg(ap, unsigned long));
	if (mod->h == 1)
		return (va_arg(ap, unsigned short int));
	if (mod->z == 1)
		return (va_arg(ap, size_t));
	if (mod->hh == 1)
		return (va_arg(ap, unsigned char));
	if (mod->j == 1)
		return (va_arg(ap, uintmax_t));
	return (va_arg(ap, unsigned int));
}

char		*work_hash(t_options *opt, char *str, int base)
{
	int			i;
	char		*temp;

	opt->hash = 0;
	i = -1;
	temp = str;
	if (str[0] == '0' && (opt->acc == ft_strlen(str)) && base == 8)
		return (str);
	while ((str[++i] == '0' || str[i] == ' ') && str[i])
		;
	if (str[i] == '\0')
		return (str);
	if (base == 16)
	{
		if (opt->capital_let == 1)
			str = ft_strjoin("0X", str);
		else
			str = ft_strjoin("0x", str);
	}
	else if (base == 8)
		str = ft_strjoin("0", str);
	if (base != 10)
		free(temp);
	return (str);
}

char		*ft_base_width(t_options *opt, char *str, int str_len, int base)
{
	int		tmp_len;
	char	symbol;

	if (opt->zero == 0 || opt->acc_flag == 1)
		symbol = ' ';
	else
		symbol = '0';
	if (opt->min == 0)
	{
		str = ft_base_w_2(opt, symbol, str, base);
	}
	else
	{
		tmp_len = opt->width - str_len - (opt->hash == 1 ? base / 8 : 0);
		str = extra_join(str, ft_memset(ft_strnew(tmp_len), ' ', tmp_len));
	}
	if (opt->hash == 1)
	{
		str = work_hash(opt, str, base);
	}
	return (str);
}

char		*ft_base(t_options *opt, va_list ap, t_modifiers *mod, int base)
{
	int		str_len;
	int		i;
	char	*res;

	i = -1;
	res = ft_itoa_base(work_un_modifier(ap, mod), base, opt->capital_let);
	str_len = ft_strlen(res);
	if (opt->acc_flag == 1)
	{
		res = ft_octal_acc(opt, res, base, str_len);
		str_len = ft_strlen(res);
	}
	while ((res[++i] == '0' || res[i] == ' ') && res[i])
		;
	if (res[i] == '\0')
		opt->hash = 0;
	if (opt->width > str_len)
	{
		res = ft_base_width(opt, res, str_len, base);
		str_len = ft_strlen(res);
	}
	if (opt->hash == 1)
		res = work_hash(opt, res, base);
	return (res);
}
