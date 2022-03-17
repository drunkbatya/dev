/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:52:52 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/02/10 16:14:09 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "db_ultimate_range.h"
#include "../putnbr/db_putnbr.h"

void	db_putchar_local(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	int	*arr;
	int	size;
	int	count;

	count = 0;
	size = db_ultimate_range(&arr, 1, 17);
	while (count < size)
	{
		db_putnbr(arr[count]);
		db_putchar_local(' ');
		count++;
	}
	return (0);
}
