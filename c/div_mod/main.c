/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:17:20 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/08 12:29:58 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db_div_mod.h"
#include "../putstr/db_putstr.h"
#include "../putnbr/db_putnbr.h"

int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = 19;
	b = 5;
	db_putstr("A: ");
	db_putnbr(a);
	db_putstr("\nB:");
	db_putnbr(b);
	db_putstr("\n");
	db_div_mod(a, b, &div, &mod);
	db_putstr("DIV: ");
	db_putnbr(div);
	db_putstr("\nMOD:");
	db_putnbr(mod);
	db_putstr("\n");
	return (0);
}
