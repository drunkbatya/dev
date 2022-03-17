/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:03:11 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/18 17:48:06 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	db_putchar(char c)
{
	write(1, &c, 1);
}

void	db_putnbr_in_base(int nbr, int div)
{
	int	div2;
	int	hex_offset;

	hex_offset = 10;
	if (div == 16)
		div2 = 10;
	else
		div2 = div;
	if (nbr < div2)
		db_putchar('0' + nbr);
	else if ((div == 16) && (nbr >= 10 && nbr < 16))
		db_putchar('a' - hex_offset + nbr);
	else
	{
		db_putnbr_in_base((nbr / div), div);
		db_putnbr_in_base((nbr % div), div);
	}
}

int	db_strcmp_hard(char *s1, char *s2)
{
	int	count;

	count = 0;
	while (s1[count] != '\0')
	{
		if (s1[count] != s2[count])
			return (1);
		count++;
	}
	if (s1[count] != s2[count])
		return (1);
	return (0);
}

void	db_putnbr_base(int nbr, char *base)
{
	if (nbr < 0)
	{
		db_putchar('-');
		nbr = -nbr;
	}
	if (db_strcmp_hard(base, "0123456789") == 0)
		db_putnbr_in_base(nbr, 10);
	else if (db_strcmp_hard(base, "0123456789ABCDEF") == 0)
		db_putnbr_in_base(nbr, 16);
	else if (db_strcmp_hard(base, "01") == 0)
		db_putnbr_in_base(nbr, 2);
	else if (db_strcmp_hard(base, "poneyvif") == 0)
		db_putnbr_in_base(nbr, 8);
}
