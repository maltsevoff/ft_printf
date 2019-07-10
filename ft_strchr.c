/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 10:21:43 by omaltsev          #+#    #+#             */
/*   Updated: 2019/03/15 16:34:51 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strchr(const char *s, int c)
{
	char	let;
	char	*tmp;

	tmp = (char *)s;
	let = c;
	while (*tmp)
	{
		if (*tmp == let)
			return (tmp);
		tmp++;
	}
	if (let == '\0')
		return (tmp);
	return (NULL);
}
