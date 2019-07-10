/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 15:58:16 by omaltsev          #+#    #+#             */
/*   Updated: 2019/03/16 15:26:20 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define ABS(x) (x) >= 0 ? (x) : -(x)

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <inttypes.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
size_t				ft_strlen(const char *str);
char				*ft_strdup(char *s1);
char				*ft_strchr(const char *s, int c);
char				*ft_strnew(size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_itoa(long long n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putstr(char const *str);

typedef struct		s_options
{
	int		min;
	int		showsign;
	int		spc;
	int		zero;
	int		hash;
	int		width;
	int		width_flag;
	int		acc;
	int		acc_flag;
	int		capital_let;
	char	sign[2];
}					t_options;

typedef struct		s_modifiers
{
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			z;
	int			j;
	int			up_l;
}					t_modifiers;

int					ft_printf(const char *format, ...);
int					general(va_list ap, char *format);
char				*ft_digit(t_options *opt, t_modifiers *mod, va_list ap);
char				*add_letter(char *s1, char let);
t_list				*add_in_end(t_list *root, char *content);
char				*ft_strndup(char *str, int n);
int					ft_strcmp(const char *s1, const char *s2);
char				*skipp(char *s1);
char				*determination(char *str, va_list ap, t_list *root);
char				*connect_str(t_list *root);
char				*accuracy(t_options *opt, char *str, va_list ap);
char				*asterisk(t_options *opt, char *str, va_list ap);
char				*width(t_options *opt, char *str);
char				*flags(t_options *opt, char *str);
char				*modifiers(t_modifiers *mod, char *str);
t_options			*set_elem();
t_modifiers			*set_modifier();
char				*choose_type(t_options *opt, t_modifiers *mod,
											va_list ap, char type);
char				*work_sign(long long num, t_options *opt);
char				*ft_digit_acc(t_options *opt, char *str, int num_len);
char				*ft_digit_width(t_options *opt, char *str, int num_len);
char				*ft_char(t_options *opt, va_list ap);
char				*ft_string(t_options *opt, va_list ap);
char				*ft_percent(t_options *opt, va_list ap);
char				*ft_itoa_base(unsigned long long number,
											int base, int high);
char				*ft_base(t_options *opt, va_list ap,
												t_modifiers *mod, int base);
long long			work_modifier(va_list ap, t_modifiers *mod);
char				*ft_float(t_options *opt, t_modifiers *mod, va_list ap);
char				*ft_point(t_options *opt, va_list ap, t_modifiers *mod);
long long			work_un_modifier(va_list ap, t_modifiers *mod);
char				*work_hash(t_options *opt, char *str, int base);
char				*ft_char_width(t_options *opt, char *str, int num_len);
char				*extra_join(char *s1, char *s2);
char				*ft_string_width(t_options *opt, char *str, int str_len);
char				*ft_itoa_f_2(int size, long double num);
char				*ft_d_width_1(int num_len, t_options *opt,
													char symbol, char *str);
char				*ft_d_width_2(int num_len, t_options *opt,
													char symbol, char *str);
char				*ft_main_acc(t_options *opt, int num_len, char *res);
char				*ft_digit_sign(t_options *opt, char *res);
char				*ft_octal_acc(t_options *opt, char *res,
													int base, int str_len);
char				*ft_base_w_2(t_options *opt, char symbol,
													char *str, int base);
char				*choose_type2(t_options *opt, t_modifiers *mod,
													va_list ap, char type);
char				*find_params(char *str, t_options *opt,
												t_modifiers *mod, va_list ap);

#endif
