/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:01:14 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/19 19:33:04 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "db_atoi_base.h"
#include "../putnbr/db_putnbr.h"

void	db_putchar_local(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	db_putnbr(db_atoi_base("   -++++-1234", "0123456789"));
	db_putchar_local('\n');
	db_putnbr(db_atoi_base(" -  ++1fF", "0123456789ABCDEF"));
	db_putchar_local('\n');
	db_putnbr(db_atoi_base("++--  ss__555", "poneyvif"));
	db_putchar_local('\n');
	db_putnbr(db_atoi_base("101111000101", "01"));
	db_putchar_local('\n');
	return (0);
}
