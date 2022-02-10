/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:11:24 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/30 17:54:16 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "db_is_prime.h"
#include "../putnbr/db_putnbr.h"

void	db_putchar_local(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	int	count;

	count = 0;
	while (count < 141)
	{
		if (db_is_prime(count))
		{
			db_putnbr(count);
			db_putchar_local(' ');
		}
		count++;
	}
	return (0);
}
