/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 12:34:07 by omaltsev          #+#    #+#             */
/*   Updated: 2019/03/15 16:34:12 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*ft_point_width(t_options *opt, char *str, int str_len)
{
	int		tmp_len;
	char	*tmp;
	char	*temp;
	char	symbol;

	temp = str;
	symbol = opt->zero == 0 ? ' ' : '0';
	if (opt->min == 0)
	{
		tmp_len = opt->width - str_len;
		tmp = ft_memset(ft_strnew(tmp_len), symbol, tmp_len);
		str = ft_strjoin(tmp, str);
		free(tmp);
	}
	else
	{
		tmp_len = opt->width - str_len;
		tmp = ft_memset(ft_strnew(tmp_len), ' ', tmp_len);
		str = ft_strjoin(str, tmp);
		free(tmp);
	}
	if (temp != NULL)
		free(temp);
	return (str);
}

char		*ft_point_2(t_options *opt, int str_len, char *res)
{
	char	*tmp;

	str_len = str_len + 2;
	if (opt->width > ft_strlen(res))
		res = ft_point_width(opt, res, str_len);
	if (opt->zero == 1)
	{
		tmp = res;
		res = ft_strjoin("0x", res);
		free(tmp);
	}
	return (res);
}

char		*ft_point(t_options *opt, va_list ap, t_modifiers *mod)
{
	int			str_len;
	char		*res;
	char		*tmp;

	res = ft_itoa_base(work_un_modifier(ap, mod), 16, 0);
	if (opt->acc_flag == 1)
	{
		if (opt->acc > ft_strlen(res))
			res = ft_digit_acc(opt, res, ft_strlen(res));
		else if (*res == '0')
			res = ft_digit_acc(opt, res, ft_strlen(res));
	}
	str_len = ft_strlen(res);
	if (opt->zero == 0)
	{
		tmp = res;
		res = ft_strjoin("0x", res);
		free(tmp);
	}
	res = ft_point_2(opt, str_len, res);
	return (res);
}
