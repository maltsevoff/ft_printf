/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 17:56:04 by omaltsev          #+#    #+#             */
/*   Updated: 2019/03/15 16:33:57 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;

	i = 0;
	if (len != 0)
	{
		while (i < len)
		{
			((unsigned char *)b)[i] = (unsigned char)c;
			i++;
		}
	}
	return (b);
}
