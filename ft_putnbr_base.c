/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:47:55 by gclausse          #+#    #+#             */
/*   Updated: 2021/12/03 17:06:01 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int     ft_putnbr_base(int nbr, char *base)
{
	int			j;
	long int	nb2;
	int			cpt;

	j = 0;
	nb2 = nbr;
	cpt = 1;
	if (nb2 < 0)
	{
		ft_putchar_fd('-', 1);
		nb2 = nb2 * -1;
		cpt++;
	}
	if (nb2 < (long)ft_strlen(base))
		ft_putchar_fd(base[nb2], 1);
	else
	{
		cpt += ft_putnbr_base(nb2 / ft_strlen(base), base);
		ft_putchar_fd(base[nb2 % ft_strlen(base)], 1);
	}
	return (cpt);
}
