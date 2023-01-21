/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:48:09 by momaiouf          #+#    #+#             */
/*   Updated: 2023/01/20 16:48:09 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int					ft_len_int(int nb);
int					ft_putnbr_int(int nb);
int					ft_len_u_int(unsigned int nb);
int					ft_putnbr_u_int(unsigned int nb);
int					ft_putchar_int(char c);
int					ft_putstr_int(char *str);
int					ft_printf(const char *str, ...);
int					get_arg_len(const char *str, int i, va_list ap);
unsigned int		ft_len_hexa(unsigned int nb);
unsigned int		ft_display_hexa(long nb, char caps);
unsigned long long	ft_len_hexa_pointer(unsigned long long nb);
unsigned long long	ft_display_hexa_pointer(unsigned long long nb);

#endif