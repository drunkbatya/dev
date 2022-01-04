/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:34:35 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/04 17:17:43 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "db_ft_ultimate.h"

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

int	main(void)
{
	int	test;
	int	*testt;
	int	**testtt;
	int	***testttt;
	int	****testtttt;
	int	*****testttttt;
	int	******testtttttt;
	int	*******testttttttt;
	int	********testtttttttt;

	testt = &test;
	testtt = &testt;
	testttt = &testtt;
	testtttt = &testttt;
	testttttt = &testtttt;
	testtttttt = &testttttt;
	testttttttt = &testtttttt;
	testtttttttt = &testttttttt;
	db_ft_ultimate(&testtttttttt);
	db_putnbr(test);
	return (0);
}
