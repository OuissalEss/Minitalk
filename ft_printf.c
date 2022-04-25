/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 06:44:19 by oessamdi          #+#    #+#             */
/*   Updated: 2022/04/25 08:34:20 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putchar(char c, int *nb)
{
	write(1, &c, 1);
	(*nb) += 1;
}

static void	ft_putstr(char *s, int *nb)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*nb += 6;
	}
	else
		while (*s)
			ft_putchar(*s++, nb);
}

static void	ft_putnbr(int n, int *nb)
{
	if (n == -2147483648)
	{
		ft_putnbr(n / 10, nb);
		ft_putchar('8', nb);
	}
	else if (n < 0)
	{
		ft_putchar('-', nb);
		ft_putnbr(n * -1, nb);
	}
	else
	{
		if (n > 9)
			ft_putnbr(n / 10, nb);
		ft_putchar(n % 10 + '0', nb);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
				ft_putchar(va_arg(args, int), &nb);
			else if (str[i] == 's')
				ft_putstr(va_arg(args, char *), &nb);
			else if (str[i] == 'd')
				ft_putnbr(va_arg(args, int), &nb);
		}
		else
			ft_putchar(str[i], &nb);
		i++;
	}
	va_end(args);
	return (nb);
}
