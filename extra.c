/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:10:56 by omaltsev          #+#    #+#             */
/*   Updated: 2019/03/15 16:32:26 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char			*add_letter(char *s1, char let)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2));
	while (*s1)
	{
		res[i] = *s1;
		i++;
		s1++;
	}
	res[i] = let;
	i++;
	res[i] = '\0';
	return (res);
}

char			*ft_strndup(char *str, int n)
{
	int		i;
	char	*res;

	res = (char*)malloc(sizeof(char) * (n + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

t_modifiers		*set_modifier(void)
{
	t_modifiers		*elem;

	elem = (t_modifiers *)malloc(sizeof(t_modifiers));
	elem->h = 0;
	elem->hh = 0;
	elem->l = 0;
	elem->ll = 0;
	elem->z = 0;
	elem->j = 0;
	elem->up_l = 0;
	return (elem);
}

t_options		*set_elem(void)
{
	t_options	*elem;

	elem = (t_options *)malloc(sizeof(t_options));
	elem->min = 0;
	elem->showsign = 0;
	elem->spc = 0;
	elem->zero = 0;
	elem->hash = 0;
	elem->width = 0;
	elem->width_flag = 0;
	elem->acc = 0;
	elem->acc_flag = 0;
	elem->capital_let = 0;
	elem->sign[0] = ' ';
	elem->sign[1] = '\0';
	return (elem);
}

char			*ft_itoa_base(unsigned long long number, int base, int high)
{
	int		tmp;
	int		ost;
	char	str_tmp[2];
	char	*res;
	char	*temp;

	res = ft_strnew(0);
	str_tmp[1] = '\0';
	while (1)
	{
		ost = number % base;
		if (ost > 9)
			str_tmp[0] = ost + '0' + (high ? 7 : 39);
		else
			str_tmp[0] = '0' + ost;
		temp = res;
		res = ft_strjoin(str_tmp, res);
		free(temp);
		number /= base;
		if (number == 0)
			break ;
	}
	return (res);
}
