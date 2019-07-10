/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:09:31 by omaltsev          #+#    #+#             */
/*   Updated: 2019/03/15 16:34:59 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*work_string(va_list ap)
{
	char	*temp;
	char	*res;

	res = va_arg(ap, char *);
	if (res == NULL)
		res = ft_strdup("(null)");
	else
		res = ft_strdup(res);
	return (res);
}

char		*ft_string_width(t_options *opt, char *str, int str_len)
{
	int		tmp_len;
	char	symbol;
	char	*s1;

	symbol = (opt->zero == 1 && opt->min == 0) ? '0' : ' ';
	tmp_len = opt->width - str_len;
	s1 = ft_memset(ft_strnew(tmp_len), symbol, tmp_len);
	if (opt->min == 1)
		str = extra_join(str, s1);
	else
		str = extra_join(s1, str);
	return (str);
}

char		*ft_string_acc(t_options *opt, char *str, int str_len)
{
	char	*temp;
	char	*res;

	temp = str;
	res = ft_strndup(str, opt->acc);
	free(temp);
	return (res);
}

char		*ft_string(t_options *opt, va_list ap)
{
	int		str_len;
	char	*res;

	res = work_string(ap);
	str_len = ft_strlen(res);
	if (opt->acc_flag == 1)
	{
		if (opt->acc < str_len)
		{
			res = ft_string_acc(opt, res, str_len);
			str_len = ft_strlen(res);
		}
		opt->acc_flag = 0;
	}
	if (opt->width > str_len)
	{
		res = ft_string_width(opt, res, str_len);
	}
	return (res);
}
