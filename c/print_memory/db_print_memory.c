/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:09:54 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/12 14:24:48 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	db_putchar(char c)
{
	write(1, &c, 1);
}

void	db_putstr(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		db_putchar(str[count++]);
}

void	db_putcolon(void)
{
	db_putchar(':');
	db_putchar(' ');
	db_putchar('\n');
}

void	db_puthex_from_dec(unsigned long nb)
{
	int	offset;

	offset = 10;
	if (nb < 10)
	{
		db_putchar('0' + nb);
	}
	else if (nb >= 10 && nb < 16)
		db_putchar('a' - offset + nb);
	else
	{
		db_putchar('0');
		db_puthex_from_dec(nb / 16);
		db_puthex_from_dec(nb % 16);
	}
}

void	db_add_hex_to_str(unsigned long *nb, unsigned long *rem, char *str)
{
	int	offset;

	offset = 10;
	*rem = *nb % 16;
	if (*rem < 10)
		*str = ('0' + *rem);
	else
		*str = ('a' - offset + *rem);
	*nb /= 16;
	str++;
}

void	db_puthex_rev(unsigned long nb)
{
	int				offset;
	int				sym_count;
	char	str[100];
	unsigned long	rem;

	offset = 10;
	while ((nb / 16) != 0)
		db_add_hex_to_str(&nb, &rem, str);
	db_add_hex_to_str(&nb, &rem, str);
	*str = '\0';
	db_putstr(str);
}

void	*db_print_memory(void *addr, unsigned int size)
{
	char	str[100];
	while (size--)
	{
		db_puthex_from_dec(addr);
		db_putcolon();
		db_puthex_rev(addr);
		db_putcolon();
	}
	return (addr);
}
