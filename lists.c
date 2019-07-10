/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:10:13 by omaltsev          #+#    #+#             */
/*   Updated: 2019/03/15 16:35:15 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list		*add_in_end(t_list *root, char *content)
{
	t_list		*work;
	t_list		*temp;

	work = root;
	if (!(work))
	{
		work = (t_list *)malloc(sizeof(t_list));
		work->next = NULL;
		work->content = ft_strdup(content);
		root = work;
	}
	else
	{
		while (work->next != NULL)
			work = work->next;
		temp = (t_list *)malloc(sizeof(t_list));
		temp->content = ft_strdup(content);
		work->next = temp;
		temp->next = NULL;
	}
	if (content)
		free(content);
	return (root);
}

char		*connect_str(t_list *root)
{
	char		*res;
	char		*tmp;
	t_list		*prev;

	res = ft_strnew(0);
	while (root != NULL)
	{
		tmp = res;
		res = ft_strjoin(res, root->content);
		free(tmp);
		prev = root;
		root = root->next;
		free(prev->content);
		free(prev);
	}
	return (res);
}
