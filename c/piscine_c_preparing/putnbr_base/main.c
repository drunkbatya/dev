/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:11:04 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/18 17:46:02 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db_putnbr_base.h"

int	main(void)
{
	db_putnbr_base(235, "0123456789");
	db_putchar('\n');
	db_putnbr_base(235, "0123456789ABCDEF");
	db_putchar('\n');
	db_putnbr_base(235, "01");
	db_putchar('\n');
	db_putnbr_base(235, "poneyvif");
	db_putchar('\n');
	db_putnbr_base(-235, "poneyvif");
	db_putchar('\n');
	db_putnbr_base(235, "poneyvif1");
	db_putnbr_base(235, "");
	db_putnbr_base(235, "01123456789");
	return (0);
}
