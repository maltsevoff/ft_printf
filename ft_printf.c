/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 12:52:40 by omaltsev          #+#    #+#             */
/*   Updated: 2019/03/15 16:34:20 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*choose_type(t_options *opt, t_modifiers *mod, va_list ap, char type)
{
	if (type == 'd' || type == 'i')
		return (ft_digit(opt, mod, ap));
	if ((type == 'D' || type == 'I') && (mod->l = 1))
		return (ft_digit(opt, mod, ap));
	if (type == '%')
		return (ft_percent(opt, ap));
	if (type == 'c')
		return (ft_char(opt, ap));
	if (type == 's')
		return (ft_string(opt, ap));
	if (type == 'o')
		return (ft_base(opt, ap, mod, 8));
	if (type == 'O' && (mod->l = 1))
		return (ft_base(opt, ap, mod, 8));
	if (type == 'x')
		return (ft_base(opt, ap, mod, 16));
	return (choose_type2(opt, mod, ap, type));
}

char	*determination(char *str, va_list ap, t_list *root)
{
	t_options	*opt;
	t_modifiers	*mod;

	opt = set_elem();
	mod = set_modifier();
	str++;
	str = find_params(str, opt, mod, ap);
	if (ft_strchr("dDioOuUxXcspfF%", *str) && *str != '\0')
	{
		add_in_end(root, choose_type(opt, mod, ap, *str));
		str++;
	}
	free(opt);
	free(mod);
	return (str);
}

char	*skipp(char *s1)
{
	s1++;
	if (*s1 == '\0')
		return (&*s1);
	while (*s1 != 'c' && *s1 != 's' && *s1 != 'p' && *s1 != 'd' && *s1 != 'i'
		&& *s1 != 'o' && *s1 != 'u' && *s1 != 'x' && *s1 != 'X' && *s1 != 'f'
		&& *s1 != '%')
	{
		if (*s1 == '\0')
			return (&*s1);
		s1++;
	}
	s1++;
	return (&*s1);
}

int		general(va_list ap, char *format)
{
	int			len;
	char		*temp;
	char		*res;
	t_list		*root;

	root = NULL;
	while (*format)
	{
		if (ft_strchr(format, '%') != NULL)
		{
			root = add_in_end(root, ft_strndup(format,
							ft_strchr(format, '%') - format));
			format = determination(ft_strchr(format, '%'), ap, root);
		}
		else
		{
			root = add_in_end(root, ft_strndup(format,
							ft_strchr(format, '\0') - format));
			break ;
		}
	}
	ft_putstr(res = connect_str(root));
	len = ft_strlen(res);
	free(res);
	return (len);
}

int		ft_printf(const char *format, ...)
{
	int			len;
	char		*gg;
	va_list		ap;

	gg = (char *)format;
	va_start(ap, format);
	len = general(ap, gg);
	va_end(ap);
	return (len);
}
