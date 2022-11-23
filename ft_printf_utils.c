/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:21:57 by yrrhaibi          #+#    #+#             */
/*   Updated: 2022/11/23 16:45:05 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	int	i;

	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long	nbr;
	int		num;

	num = 0;
	nbr = n;
	if (nbr < 0)
	{
		num += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
	{
		num += ft_putnbr(nbr / 10);
		num += ft_putnbr(nbr % 10);
	}
	else
	{
		num += ft_putchar(nbr + 48);
	}
	return (num);
}

int	ft_putnbr_uns(unsigned int n)
{
	long	nbr;
	int		num;

	num = 0;
	nbr = n;
	
	if (nbr > 9)
	{
		num += ft_putnbr(nbr / 10);
		num += ft_putnbr(nbr % 10);
	}
	else
	{
		num += ft_putchar(nbr + 48);
	}
	return (num);
}

int	ft_p(uintptr_t n)
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
