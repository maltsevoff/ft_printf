/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 11:52:28 by omaltsev          #+#    #+#             */
/*   Updated: 2019/03/16 12:27:59 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*ft_main_acc(t_options *opt, int num_len, char *res)
{
	char	*tmp;

	if (opt->acc > num_len)
		res = ft_digit_acc(opt, res, num_len);
	if (ft_strcmp("0", res) == 0 && opt->acc == 0)
	{
		tmp = res;
		res = ft_strnew(0);
		free(tmp);
	}
	if (opt->showsign == 1)
	{
		tmp = res;
		res = ft_strjoin(opt->sign, res);
		free(tmp);
		opt->showsign = 0;
	}
	return (res);
}

char		*ft_digit_sign(t_options *opt, char *res)
{
	char	*tmp;

	if (opt->width_flag == 0 && opt->acc_flag == 0 && opt->showsign == 1)
	{
		tmp = res;
		res = ft_strjoin(opt->sign, res);
		free(tmp);
	}
	if (opt->width_flag == 0 && opt->acc_flag == 0 && opt->showsign == 0
		&& opt->spc == 1)
	{
		tmp = res;
		res = ft_strjoin(" ", res);
		free(tmp);
	}
	return (res);
}
