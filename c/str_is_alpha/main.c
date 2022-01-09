/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:11:55 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/09 14:10:02 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../strcpy/db_strcpy.h"
#include "../putnbr/db_putnbr.h"
#include "../putchar/db_putchar.h"
#include "db_str_is_alpha.h"

int	main(void)
{
	char	str1[10];
	char	str2[10];
	char	stre[10];

	db_strcpy(str1, "TeststrFD");
	db_strcpy(str2, "F1ck");
	db_putnbr(db_str_is_alpha(str1));
	db_putchar(' ');
	db_putnbr(db_str_is_alpha(str2));
	db_putchar(' ');
	db_putnbr(db_str_is_alpha(stre));
	db_putchar('\n');
	return (0);
}
