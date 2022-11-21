/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hlp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 02:39:56 by yrrhaibi          #+#    #+#             */
/*   Updated: 2022/11/21 02:44:00 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hexu(unsigned int n)
{
	char	*b;
	int		num;

	b = "0123456789abcdef";
	num = 0;
	if (n < 16)
		num += ft_putchar(b[n]);
	else
	{
		num += ft_p(n / 16);
		num += ft_p(n % 16);
	}
	return (num);
}

int	put_hexl(unsigned int n)
{
	char	*b;
	int		num;

	b = "0123456789ABCDEF";
	num = 0;
	if (n < 16)
		num += ft_putchar(b[n]);
	else
	{
		num += ft_p(n / 16);
		num += ft_p(n % 16);
	}
	return (num);
}
