/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:47:55 by gclausse          #+#    #+#             */
/*   Updated: 2021/12/03 15:54:41 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int     ft_putnbr_base(int nbr, char *base)
{
	int			j;
	int			base_len;
	long int	nb2;
	int			cpt;

	j = 0;
	base_len = ft_strlen(base);
	nb2 = nbr;
	cpt = 1;
	while (nb2 / 10)
	{
		nb2 = nb2 / 10;
		cpt++;
	}
	nb2 = nbr;
	if (nb2 < 0)
	{
		ft_putchar_fd('-', 1);
		nb2 = nb2 * -1;
		cpt++;
	}
	if (nb2 < base_len)
		ft_putchar_fd(base[nb2], 1);
	else
	{
		ft_putnbr_base(nb2 / base_len, base);
		ft_putchar_fd(base[nb2 % base_len], 1);
	}
	return (cpt);
}
