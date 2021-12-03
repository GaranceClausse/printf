/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:54:32 by gclausse          #+#    #+#             */
/*   Updated: 2021/12/03 17:38:36 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

static int	ft_putstr(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		i += 6;
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	va_list	vl;

	va_start(vl, str);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] != '%' && str[i])
		{
			ft_putchar_fd(str[i], 1);
			i++;
			j++;
		}
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c')
			{
				ft_putchar(va_arg(vl, int), 1);
				j++;
			}
			else if (str[i + 1] == 's')
				j = j + ft_putstr(va_arg(vl, char *), 1);
			else if (str[i + 1] == 'p')
			{
			}
			else if (str[i + 1] == 'd' || str[i + 1] == 'i')
				j = j + ft_putnbr_base(va_arg(vl, int), "0123456789");
			else if (str[i + 1] == 'u')
				j = j + ft_putnbr_base_unsgn(va_arg(vl, unsigned int), "0123456789");
			else if (str[i + 1] == 'x')
				j = j + ft_putnbr_base_unsgn(va_arg(vl, unsigned int), "0123456789abcdef");
			else if (str[i + 1] == 'X')
				j = j + ft_putnbr_base_unsgn(va_arg(vl, unsigned int), "0123456789ABCDEF");
			else if (str[i + 1] == '%')
			{
				ft_putchar_fd('%', 1);
				j++;
			}
			i++;
		}
		if (str[i])
			i++;
	}
	va_end(vl);
	return (j);
}
