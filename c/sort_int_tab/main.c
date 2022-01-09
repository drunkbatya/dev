/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:10:34 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/08 14:25:12 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../putnbr/db_putnbr.h"
#include "../putchar/db_putchar.h"
#include "db_sort_int_tab.h"
#define SIZE 12

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
