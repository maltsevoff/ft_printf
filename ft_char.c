/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 17:36:06 by omaltsev          #+#    #+#             */
/*   Updated: 2019/03/15 16:33:00 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*ft_char_width(t_options *opt, char *str, int num_len)
{
	int		tmp_len;
	char	*tmp;
	char	*temp;
	char	symbol;

	temp = str;
	symbol = (opt->zero == 0 || opt->acc_flag == 1) ? ' ' : '0';
	if (opt->min == 0)
	{
		tmp_len = opt->width - num_len;
		tmp = ft_memset(ft_strnew(tmp_len), symbol, tmp_len);
		str = ft_strjoin(tmp, str);
		free(tmp);
	}
	else
	{
		tmp_len = opt->width - num_len;
		tmp = ft_memset(ft_strnew(tmp_len), ' ', tmp_len);
		str = ft_strjoin(str, tmp);
		free(tmp);
	}
	if (temp != NULL)
		free(temp);
	return (str);
}

char		*ft_percent(t_options *opt, va_list ap)
{
	int		str_len;
	char	*res;

	res = ft_strdup("%");
	str_len = ft_strlen(res);
	opt->acc_flag = 0;
	opt->spc = 0;
	if (opt->width > str_len)
	{
		res = ft_char_width(opt, res, str_len);
	}
	return (res);
}

char		*work_char(va_list ap)
{
	char	*res;
	char	letter;

	res = ft_strnew(2);
	letter = va_arg(ap, char);
	res[0] = letter;
	res[1] = '\0';
	if (res[0] == '\0')
		res[0] = -42;
	return (res);
}

char		*ft_char(t_options *opt, va_list ap)
{
	int		str_len;
	char	*res;

	res = work_char(ap);
	str_len = ft_strlen(res);
	opt->acc_flag = 0;
	if (opt->width > str_len)
	{
		res = ft_char_width(opt, res, str_len);
	}
	return (res);
}
