/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:30:19 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/27 12:15:04 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db_fibonacci.h"
#include "../putnbr/db_putnbr.h"
#include <unistd.h>

void	db_putchar_local(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	int	num;

	num = 40;
	db_putnbr(db_fibonacci_it(num));
	db_putchar_local('\n');
	db_putnbr(db_fibonacci(num));
	return (0);
}
