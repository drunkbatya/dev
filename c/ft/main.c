/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:34:35 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/04 16:35:54 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "db_ft.h"

void	db_putchar(char c)
{
	write(1, &c, 1);
}

void	db_putnbr(int nb)
{
	if (nb < 0)
	{
		nb = -nb;
		db_putchar('-');
	}
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

int	main(void)
{
	int	test;

	db_ft(&test);
	db_putnbr(test);
	return (0);
}
