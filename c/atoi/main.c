/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:19:29 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/16 14:39:13 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../strcpy/db_strcpy.h"
#include "db_atoi.h"
#include "unistd.h"

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

void	db_putstr(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		db_putchar(str[count++]);
}

int	main(void)
{
	char	str[100];

	db_putstr(db_strcpy(str, "  -  !!1456-daf4545"));
	db_putstr("\n");
	db_putnbr(db_atoi(str));
	db_putstr("\n");
	return (0);
}
