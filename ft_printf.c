/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:54:32 by gclausse          #+#    #+#             */
/*   Updated: 2021/12/02 17:37:31 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	vl;

	va_start(vl, str);
	i = 0;
	while (str[i] && str[i] != '%')
	{
		ft_putchar_fd(str[i], 1);
		if (str[i + 1] == '%')
		{
			i++;
			if (str[i + 1] == 'c')
			{
				ft_putchar_fd(va_arg(vl, int), 1);
				i++;
			}
			if (str[i + 1] == 's')
			{
				ft_putstr_fd(va_arg(vl, char *), 1);
				i++;
			}
			if (str[i + 1] == 'p')
			{
			
			}
			if (str[i + 1] == 'd' || str[i + 1] == 'i')
			{
				ft_putnbr_base(va_arg(vl, int), "0123456789");
				i++;
			}
			if (str[i + 1] == 'u')
			{
				ft_putnbr_base(va_arg(vl, unsigned int), "0123456789");
				i++;
			}
			if (str[i + 1] == 'x')
			{
				ft_putnbr_base(va_arg(vl, unsigned int), "abcdef0123456789");
				i++;
			}
			if (str[i + 1] == 'X')
			{
				ft_putnbr_base(va_arg(vl, unsigned int), "ABCDEF0123456789");
				i++;
			}
			if (str[i + 1] == '%')
			{
				ft_putchar_fd('%', 1);
				i++;
			}
		}
		i++;
	}
	va_end(vl);
	return (0);
}

int	main()
{
	printf("Bonjour  %c   %s\n", '?', "ca maaaaarche");

	ft_printf("Bonjour  %c      %s ",  '?', "ca maaaaarche!!!!");

}

