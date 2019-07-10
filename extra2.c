/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:24:54 by omaltsev          #+#    #+#             */
/*   Updated: 2019/03/15 16:32:37 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*extra_join(char *s1, char *s2)
{
	char	*res;
	char	*tmp;
	char	*tmp1;

	tmp = s1;
	tmp1 = s2;
	res = ft_strjoin(s1, s2);
	free(tmp);
	free(tmp1);
	return (res);
}

char		*ft_itoa_f_2(int size, long double num)
{
	int			i;
	long double	tmp;
	char		*res;

	res = ft_strnew(size);
	i = 0;
	while (size > 0)
	{
		num *= 10;
		tmp = num + 48;
		res[i] = tmp;
		num = num - (long long)num;
		size--;
		i++;
	}
	return (res);
}

char		*ft_d_width_1(int num_len, t_options *opt, char symbol, char *str)
{
	int		tmp_len;
	char	*tmp;

	tmp_len = opt->width - num_len - opt->spc;
	tmp = ft_memset(ft_strnew(tmp_len), symbol, tmp_len);
	str = ft_strjoin(tmp, str);
	free(tmp);
	if (symbol == ' ' && opt->showsign == 1 && opt->acc_flag == 0)
		str[tmp_len - 1] = opt->sign[0];
	return (str);
}

char		*ft_d_width_2(int num_len, t_options *opt, char symbol, char *str)
{
	int		tmp_len;
	char	*tmp;

	tmp_len = opt->width - num_len - opt->showsign - opt->spc;
	tmp = ft_memset(ft_strnew(tmp_len), ' ', tmp_len);
	str = ft_strjoin(str, tmp);
	free(tmp);
	if (opt->showsign == 1 && opt->acc_flag == 0)
		str = ft_strjoin(opt->sign, str);
	return (str);
}
