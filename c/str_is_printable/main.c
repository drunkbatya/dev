/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:11:55 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/09 15:24:50 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../strcpy/db_strcpy.h"
#include "../putnbr/db_putnbr.h"
#include "../putchar/db_putchar.h"
#include "db_str_is_printable.h"

int	main(void)
{
	char	str1[10];
	char	str2[10];
	char	stre[10];

	db_strcpy(str1, "AABBRTTG\t");
	db_strcpy(str2, "000!");
	db_putnbr(db_str_is_printable(str1));
	db_putchar(' ');
	db_putnbr(db_str_is_printable(str2));
	db_putchar(' ');
	db_putnbr(db_str_is_printable(stre));
	db_putchar('\n');
	return (0);
}
