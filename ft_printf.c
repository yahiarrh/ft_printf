/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:21:55 by yrrhaibi          #+#    #+#             */
/*   Updated: 2022/11/23 16:58:19 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	if_conv(char s)
{
	char	*f;

	f = "cspdiuxX%";
	while (*f)
	{
		if (s == *f)
			return (1);
		f++;
	}
	return (0);
}

int	prt(va_list reg, const char *arg)
{
	int	count;

	count = 0;
	if (*arg == 'c')
		count += ft_putchar(va_arg(reg, int));
	else if (*arg == 's')
		count += ft_putstr(va_arg(reg, char *));
	else if (*arg == 'd' || *arg == 'i')
		count += ft_putnbr(va_arg(reg, int));
	else if (*arg == 'u')
		count += ft_putnbr_uns(va_arg(reg, int));
	else if (*arg == 'p')
	{
		count += ft_putstr("0x");
		count += ft_p(va_arg(reg, uintptr_t));
	}
	else if (*arg == 'x')
		count += put_hexl(va_arg(reg, unsigned int));
	else if (*arg == 'X')
		count += put_hexu(va_arg(reg, unsigned int));
	else if (*arg == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *arg, ...)
{
	va_list	reg;
	int		num;

	num = 0;
	va_start(reg, arg);
	if (!arg)
		return (0);
	while (*arg)
	{
		if (*arg == '%' && if_conv(*(arg + 1)))
		{	
			arg++;
			num += prt(reg, arg);
		}
		else if (*arg != '%')
			num += ft_putchar(*arg);
		++arg;
	}
	va_end (reg);
	return (num);
}
