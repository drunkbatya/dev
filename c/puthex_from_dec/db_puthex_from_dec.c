/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_puthex_from_dec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:49:24 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/11 15:43:30 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include <stdio.h>

void	db_putchar(char c)
{
	write(1, &c, 1);
}

void	db_puthex_from_dec(long nb)
{
	int	offset;
	printf("Current nb: %ld\n", nb);

	offset = 10;
	if (nb < 10)
	{
		db_putchar('0' + nb);
	}
	else if (nb >= 10 && nb < 16)
		db_putchar('a' - offset + nb);
	else
	{
		db_putchar('0');
		db_puthex_from_dec(nb / 16);
		db_puthex_from_dec(nb % 16);
	}
}
