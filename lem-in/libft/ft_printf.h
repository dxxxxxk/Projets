/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaigno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:40:40 by rchaigno          #+#    #+#             */
/*   Updated: 2019/10/15 16:40:42 by rchaigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct			s_opt
{
	char				m;
	char				p;
	char				po;
	char				z;
	char				e;
	char				d;
	int					larg;
	int					preci;
	char				len;
	char				type;
}						t_opt;

int						ft_union5(const char *format, int i, t_opt *val);
int						ft_union4(char *tmp, int ret);
char					*ft_union3(char *str, char *tmp);
char					*ft_union2(char *str, long int intpart, char *tmp);
char					*ft_union(char *str, char *tmp, char *tmp2,
						long double len);
int						ft_op_xx_1(t_opt *val, int ret, char *str, int len);
int						ft_op_xx_2(t_opt *val, int ret, char *str);
int						ft_op_x_1(t_opt *val, int ret, char *str, int len);
int						ft_op_x_2(t_opt *val, int ret, char *str);
int						ft_op_o_1(t_opt *val, int ret, char *str, int len);
int						ft_op_o_2(t_opt *val, int ret, char *str);
int						ft_op_u_1(t_opt *val, int ret, char *str, int len);
int						ft_op_u_2(t_opt *val, int ret, char *str);
int						ft_op_s_1(t_opt *val, int ret, char *str, int len);
int						ft_op_p_1(t_opt *val, int ret, char *str, int len);
int						ft_op_p_2(t_opt *val, int ret, char *str);
int						ft_op_d_1(t_opt *val, int ret, char *str, int len);
int						ft_op_d_2(t_opt *val, int ret, char *str);
int						ft_nnnnnorm(const char *format, int i, t_opt *val);
int						ft_nnnnormes(const char *format, int i, t_opt *val);
int						ft_print_preci(t_opt *val, char *str, int ret);
int						ft_nnnnorme(t_opt *val, char *str, int *len, int ret);
int						ft_nnnnorm(t_opt *val, char *str, int ret);
int						ft_nnnormes(t_opt *val, char *str, int ret, int *len);
int						ft_nnnorme(t_opt *val, char *str, int ret, int *len);
int						ft_nnnorm(t_opt *val, char *str, int ret, int *len);
int						ft_nnormes(t_opt *val, char *str, int ret, int *len);
char					*ft_nnorme(t_opt *val, long double lenn, int *len);
int						ft_nnorm(char *str, int i, int ret, t_opt *val);
int						ft_normes(char *str, int ret, int *i);
int						ft_norme(char *str, int i, int ret);
char					*ft_norm(long int *part, long double len, char *str);
int						ft_format(int *i, int ret, const char *format);
int						ft_diff(char *str, t_opt *val, int diff, int len);
int						ft_putox(t_opt *val, int ret);
int						ft_ps(t_opt *val, int ret, int diff);
int						ft_opt_m(t_opt *val, int len, int ret, char *str);
int						ft_operation(t_opt *val, int ret, char *str);
int						ft_opt(t_opt *val, int len, int ret);
int						ft_opt_d(t_opt *val, int len, int ret, char *str);
int						ft_printf(const char *format, ...);
void					ft_initialisation(t_opt *val);
int						ft_analyse(const char *format, int i, t_opt *val);
int						ft_print_all(t_opt *val, va_list args, int ret);
int						ft_print_c(t_opt *val, va_list args, int ret);
int						ft_print_s(t_opt *val, va_list args, int ret);
int						ft_print_p(t_opt *val, va_list args, int ret);
int						ft_print_d(t_opt *val, va_list args, int ret);
int						ft_print_o(t_opt *val, va_list args, int ret);
int						ft_print_u(t_opt *val, va_list args, int ret);
int						ft_print_xx(t_opt *val, va_list args, int ret);
int						ft_print_x(t_opt *val, va_list args, int ret);
int						ft_print_f(t_opt *val, va_list args, int ret);
long long int			ft_print_conversion(va_list args, t_opt *val);
unsigned long long int	ft_print_conversions(va_list args, t_opt *val);
long double				ft_print_conv(va_list args, t_opt *val);
char					*ft_itoa_num(unsigned long long int val, int base,
						int num);

#endif
