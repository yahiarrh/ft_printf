/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:47:48 by yrrhaibi          #+#    #+#             */
/*   Updated: 2022/11/21 20:00:13 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *arg, ...);
int	prt(va_list reg, const char *arg);
int	if_conv(char s);
int	ft_putnbr_uns(int n);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	put_hexl(unsigned int n);
int	put_hexu(unsigned int n);
int	ft_p(uintptr_t n);

#endif