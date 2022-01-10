/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_puthex_from_dec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:49:24 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/10 20:21:26 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	db_putchar(char c)
{
	write(1, &c, 1);
}

void	db_puthex_from_dec(long nb)
{
	int		offset;
	long	su;

	offset = 10;
	if (nb < 10)
	{
		db_putchar('0' + nb);
	}
	else if (nb >= 10 && nb <= 16)
		db_putchar('a' - offset + nb);
	else if ((nb / 16) != 0)
	{
		su = nb % 16;
		nb = nb / 16;
		db_puthex_from_dec(nb);
		db_puthex_from_dec(su);
	}
}
