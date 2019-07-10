/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 11:51:41 by omaltsev          #+#    #+#             */
/*   Updated: 2019/03/16 12:28:09 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_octal_acc(t_options *opt, char *res, int base, int str_len)
{
	char	*temp;

	if (opt->acc > str_len)
		res = ft_digit_acc(opt, res, str_len);
	if (opt->acc == 0 && res[0] == '0' && (base != 8 ||
		(base == 8 && opt->hash == 0)))
	{
		temp = res;
		res = ft_strnew(0);
		free(temp);
		if (base == 16)
			opt->hash = 0;
	}
	str_len = ft_strlen(res);
	if (opt->hash == 1)
		res = work_hash(opt, res, base);
	return (res);
}

char	*some_work(char symbol, t_options *opt, int base, char *str)
{
	int		tmp_len;
	int		str_len;

	str_len = ft_strlen(str);
	if (symbol == ' ')
	{
		str = work_hash(opt, str, base);
		str_len = ft_strlen(str);
		tmp_len = opt->width - str_len;
		str = extra_join(ft_memset(ft_strnew(tmp_len),
									symbol, tmp_len), str);
	}
	if (symbol == '0')
	{
		tmp_len = opt->width - str_len - (*str != '0' ? (base / 8) : 0);
		str = extra_join(ft_memset(ft_strnew(tmp_len),
									symbol, tmp_len), str);
		str = work_hash(opt, str, base);
	}
	return (str);
}

char	*ft_base_w_2(t_options *opt, char symbol, char *str, int base)
{
	int		tmp_len;
	int		str_len;

	str_len = ft_strlen(str);
	if (opt->hash == 1)
		str = some_work(symbol, opt, base, str);
	else
	{
		tmp_len = opt->width - str_len;
		str = extra_join(ft_memset(ft_strnew(tmp_len),
									symbol, tmp_len), str);
	}
	return (str);
}
