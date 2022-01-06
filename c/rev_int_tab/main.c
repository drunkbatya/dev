/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:59:12 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/06 15:31:30 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../putnbr/db_putnbr.h"
#include "../putchar/db_putchar.h"
#include "db_rev_int_tab.h"
#define SIZE 13

int	main(void)
{
	int	arr[SIZE] = {45, 46, 47, 48, 49, 50, 61, 72, 83, 88, 99, 100, 200};
	int	count;

	count = 0;
	while (count < SIZE)
	{
		db_putnbr(arr[count++]);
		db_putchar(' ');
	}
	db_putchar('\n');
	db_rev_int_tab(arr, SIZE);
	count = 0;
	while (count < SIZE)
	{
		db_putnbr(arr[count++]);
		db_putchar(' ');
	}
	return (0);
}
