/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_comb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 09:28:16 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/04 14:54:16 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	db_putchar(char c)
{
	write(1, &c, 1);
}

void	db_putsplit(void)
{
	db_putchar(',');
	db_putchar(' ');
}

void	db_print_comb(void)
{
	int	one;
	int	two;
	int	three;

	one = '0' - 1;
	while (one++ < '9')
	{
		two = '0' - 1;
		while (two++ < '9')
		{
			three = '0' - 1;
			while (three++ < '9')
			{
				if (one < two && two < three)
				{
					db_putchar(one);
					db_putchar(two);
					db_putchar(three);
					if (!(one == '7' && two == '8' && three == '9'))
						db_putsplit();
				}
			}
		}
	}
}
