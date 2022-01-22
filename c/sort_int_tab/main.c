/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:10:34 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/20 18:20:01 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db_sort_int_tab.h"
#include <unistd.h>
#define SIZE 12

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
	int	arr[SIZE] = {32, 16, 24, 33, 1008, 65, 59, 63, 76, 81, 99, 120};
	int	count;

	count = 0;
	while (count < SIZE)
	{
		db_putnbr(arr[count++]);
		db_putchar(' ');
	}
	db_putchar('\n');
	db_sort_int_tab(arr, SIZE);
	count = 0;
	while (count < SIZE)
	{
		db_putnbr(arr[count++]);
		db_putchar(' ');
	}
	db_putchar('\n');
	return (0);
}
