/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:09:54 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/10 14:47:04 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	db_putchar(char c)
{
	write(1, &c, 1);
}

void	db_putnbr(unsigned long nb)
{
	if (nb < 10)
	{
		db_putchar('0' + nb);
	}
	else
	{
		db_putnbr(nb / 10);
		db_putnbr(nb % 10);
	}
}

void	*db_print_memory(void *addr, unsigned int size)
{
	unsigned long	*adr;

	adr = (unsigned long *)addr;
	db_putnbr(*adr);
	return (addr);
}
