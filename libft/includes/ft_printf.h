/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmohr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 02:15:30 by tmohr             #+#    #+#             */
/*   Updated: 2016/10/12 17:21:53 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"
# include <stdarg.h>
# include <locale.h>

# define TJ tab[2]
# define FLM tab[3]
# define LARGE tab[4]
# define PRECIS tab[5]
# define COUNT tab[0]
# define MODZ tab[6]
# define LU tab[7]
# define LD tab[8]
# define FLP tab[9]
# define FLS tab[10]
# define FLD tab[11]
# define MODL tab[12]
# define MODLL tab[13]
# define MODH tab[14]
# define MODHH tab[15]
# define MODJ tab[16]
# define FLZ tab[17]
# define NEG tab[18]
# define TYPEX tab[20]
# define TEMP tab[19]

int		*ft_check_mod(int *tab, char mod1, char mod2);
int		*ft_flags(const char *restrict format, int *tab);
int		*ft_format(int *j, const char *restrict format, int *tab);
int		*ft_format2(int *j, const char *restrict format, int *tab);
int		*ft_format3(int *j, const char *restrict format, int *tab, va_list el);
int		*ft_format4(int *j, const char *restrict format, int *tab, va_list el);
int		*ft_format5(int *j, const char *restrict format, int *tab);
int		*ft_format6(int *j, const char *restrict format, int *tab, int i);
int		*ft_format7(int j, const char *restrict format, int *tab, va_list el);
int		ft_diese(int *tab);
int		ft_diese_test(char format);
int		ft_diese_test2(char format);
char	*case_null(void);
int		ft_printf(const char *restrict format, ...);
char	*checking_f(char *str, int length);
char	*ft_checkdister(char *str, int flz, int flm);
char	*ft_checkxster(char *str, int flz);
char	*ft_checkgxster(char *str, int flz);
int		ft_itemgs(va_list el, int *tab);
int		ft_wchar(unsigned int v);
void	ft_mask_one(unsigned int v, unsigned char octet);
void	ft_mask_two(unsigned int v, unsigned char octet);
void	ft_mask_three(unsigned int v, unsigned char octet);
int		ft_itemgc(va_list el, int *tab);
int		binary_nb(unsigned int nb);
char	*ft_fitxl(unsigned long long int value, int base, char *str, int c);
char	*ft_fitgx(unsigned long long int value, int base, char *str, int c);
int		ft_length_itoa_xull(unsigned long long int value, int base);
char	*ft_itoa_base_xull(unsigned long long int value, int base, int c);
char	*ft_itoa_base_gxull(unsigned long long int value, int base, int c);
char	*ft_itemx_precis_xull(int *tab, char *str, int c);
char	*ft_fitxsl(long long int value, int base, char *str, int c);
int		ft_length_itoa_sll(long long int value, int base);
char	*ft_itoa_base_sll(long long int value, int base, int c);
char	*ft_itemx_precis_xsll(int *tab, char *str, int c);
char	*ft_itemdi_flags(int *tab, char *str);
int		ft_itemp_global(va_list el, int *tab, int i);
int		ft_itemx_l(va_list el, int *tab);
int		ft_itemx_ll(va_list el, int *tab);
int		ft_itemx_h(va_list el, int *tab);
int		ft_itemx_hh(va_list el, int *tab);
int		ft_itemx_j(va_list el, int *tab);
int		ft_itemx_z(va_list el, int *tab);
int		ft_itemgx_l(va_list el, int *tab);
int		ft_itemgx_ll(va_list el, int *tab);
int		ft_itemgx_h(va_list el, int *tab);
int		ft_itemgx_hh(va_list el, int *tab);
int		ft_itemgx_j(va_list el, int *tab);
int		ft_itemgx_z(va_list el, int *tab);
int		ft_itemo_l(va_list el, int *tab);
int		ft_itemo_ll(va_list el, int *tab);
int		ft_itemo_h(va_list el, int *tab);
int		ft_itemo_hh(va_list el, int *tab);
int		ft_itemo_j(va_list el, int *tab);
int		ft_itemo_z(va_list el, int *tab);
int		ft_itemb_l(va_list el, int *tab);
int		ft_itemb_ll(va_list el, int *tab);
int		ft_itemb_h(va_list el, int *tab);
int		ft_itemb_hh(va_list el, int *tab);
int		ft_itemb_j(va_list el, int *tab);
int		ft_itemb_z(va_list el, int *tab);
int		ft_itemb(va_list el, int *tab);
int		ft_itemu_l(va_list el, int *tab);
int		ft_itemu_ll(va_list el, int *tab);
int		ft_itemu_h(va_list el, int *tab);
int		ft_itemu_hh(va_list el, int *tab);
int		ft_itemu_j(va_list el, int *tab);
int		ft_itemu_z(va_list el, int *tab);
int		ft_itemdi_l(va_list el, int *tab);
int		ft_itemdi_ll(va_list el, int *tab);
int		ft_itemdi_h(va_list el, int *tab);
int		ft_itemdi_hh(va_list el, int *tab);
int		ft_itemdi_j(va_list el, int *tab);
int		ft_itemdi_z(va_list el, int *tab);
char	*make_the_str_x(char *str);
char	*make_the_str_gx(char *str);
char	*ft_itemx_large2(int *tab, char *str, char *str3, char var);
char	*ft_itemx_large(int *tab, char *str);
char	*ft_itemx_flags(int *tab, char *str);
char	*ft_itemgx_flags(int *tab, char *str);
char	*ft_itemo_flags(int *tab, char *str);
char	*ft_itemu_flags(char *str);
int		ft_items_global(va_list el, int *tabi, int i);
int		ft_itemc_global(va_list el, int *tab, int i);
int		ft_itemu_global(va_list el, int *tab, int i);
int		ft_itemdi_global(va_list el, int *tab, int i);
int		ft_itemo_global(va_list el, int *tab, int i);
int		ft_itemx_global(va_list el, int *tab, int i);
int		ft_itemgx_global(va_list el, int *tab, int i);
int		ft_itemb_global(va_list el, int *tab, int i);
int		ft_special(const char *restrict format, va_list el, int *tab);
int		ft_special2(const char *restrict format, va_list el, int *tab, int j);
int		ft_percent(int i);
int		ft_items(va_list el, int *tab);
int		ft_items_special(char *str, int *tab);
int		ft_itemc(va_list el, int *tab);
int		ft_itemdi(va_list el, int *tab);
int		ft_itemo(va_list el, int *tab);
int		ft_itemx(va_list el, int *tab);
int		ft_itemgx(va_list el, int *tab);
int		ft_itemu(va_list el, int *tab);
int		ft_special(const char *restrict format, va_list el, int *tab);
int		*ft_printf2(const char *restrict format, va_list el, int *tab);
#endif
