/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:47:55 by gclausse          #+#    #+#             */
/*   Updated: 2021/12/02 17:12:28 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void     ft_putnbr_base(int nbr, char *base)
{
	int			j;
	int			base_len;
	long int	nb2;

	j = 0;
	base_len = ft_strlen(base);
	nb2 = nbr;
	if (nb2 < base_len)
		ft_putchar_fd(base[nb2], 1);
	else
	{
		ft_putnbr_base(nb2 / base_len, base);
		ft_putchar_fd(base[nb2 % base_len], 1);
	}
}	
