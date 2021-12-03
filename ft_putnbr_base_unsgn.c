/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_unsgn.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:26:29 by gclausse          #+#    #+#             */
/*   Updated: 2021/12/03 16:33:03 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int     ft_putnbr_base_unsgn(unsigned int nbr, char *base)
{
	int			j;
	long int	nb3;
	long int	nb2;
	int			cpt;

	j = 0;
	cpt = 1;
	if (nbr < 0)
		nb2 = nbr + 2147483648;
	else
		nb2 = nbr;
	nb3 = nb2;
	while (nb3 / 10)
	{
		nb3 = nb3 / 10;
		cpt++;
	}
	if (nb2 < (long)ft_strlen(base))
		ft_putchar_fd(base[nb2], 1);
	else
	{
		ft_putnbr_base(nb2 / ft_strlen(base), base);
		ft_putchar_fd(base[nb2 % ft_strlen(base)], 1);
	}
	return (cpt);
}
