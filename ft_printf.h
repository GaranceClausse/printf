/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:49:50 by gclausse          #+#    #+#             */
/*   Updated: 2021/12/03 19:52:51 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libc.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_putnbr_base(int nbr, char *base);
int	ft_putnbr_base_unsgn(unsigned int nbr, char *base);
int ft_putnbr_usgn_lg(unsigned long int nbr, char *base);
int	ft_printf(const char *str, ...);

#endif
