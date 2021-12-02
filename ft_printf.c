/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:54:32 by gclausse          #+#    #+#             */
/*   Updated: 2021/12/02 14:50:22 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '%')
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	if (str[i] == '%')
	{
		if (str[i + 1] == 'c')
		{
			ft_putchar_fd(va_arg, 1);
		}
		if (str[i + 1] == 's')
		{
			ft_putstr_fd(va_arg, 1);
		}
		if (str[i + 1] == 'p')
		{
			
		}
		if (str[i + 1] == 'd')
		{
			ft_putnbr_base(va_arg, 10);
		}
		if (str[i + 1] == 'i')
		{
			ft_putnbr_base(va_arg, 10);
		}
		if (str[i + 1] == 'u')
		{
			ft_putnbr_base(va_arg, 10);
		}
		if (str[i + 1] == 'x')
		{
			ft_putnbr_base(va_arg, "abcdef123456789");
		}
		if (str[i + 1] == 'X')
		{
			ft_putnbr_base(va_arg, "ABCDEF123456789");
		}
		if (str[i + 1] == '%')
		{
			ft_putchar_fd('%', 1);
		}

	}
}
