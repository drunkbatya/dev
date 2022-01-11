/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:09:54 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/11 15:58:12 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	db_putchar(char c)
{
	write(1, &c, 1);
}

void	db_putcolon(void)
{
	db_putchar(':');
	db_putchar(' ');
}

void	db_puthex_from_dec(unsigned long nb)
{
	int	offset;

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

void	*db_print_memory(void *addr, unsigned int size)
{
	unsigned long	*adr;

	adr = (unsigned long *)addr;
	while (size--)
	{

		db_puthex_from_dec(&adr);
		db_putcolon();
	}
	return (addr);
}
