/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:34:51 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/08 13:03:45 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db_div_mod_ultimate.h"
#include "../putstr/db_putstr.h"
#include "../putnbr/db_putnbr.h"

int	main(void)
{
	int	a;
	int	b;

	a = 19;
	b = 5;
	db_putstr("A: ");
	db_putnbr(a);
	db_putstr("\nB:");
	db_putnbr(b);
	db_putstr("\n");
	db_div_mod_ultimate(&a, &b);
	db_putstr("A: ");
	db_putnbr(a);
	db_putstr("\nB:");
	db_putnbr(b);
	db_putstr("\n");
	return (0);
}
