/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:49:50 by gclausse          #+#    #+#             */
/*   Updated: 2021/12/03 20:49:09 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libc.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_putnbr_base(int nbr, char *base);
int	putusg(unsigned int nbr, char *base);
int putul(unsigned long int nbr, char *base);
int	ft_printf(const char *str, ...);

#endif
