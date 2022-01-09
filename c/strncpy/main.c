/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:09:07 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/09 13:00:11 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db_strncpy.h"
#include "../putstr/db_putstr.h"
#include "../putnbr/db_putnbr.h"

int	main(void)
{
	int		count;
	char	str[100] = "Testiqqqqqqq";
	char	str2[108] = "123456789";

	count = 0;
	db_putstr(str);
	db_putstr(" ");
	db_putstr(str2);
	db_putstr("\n");
	db_strncpy(str2, str, 4);
	db_putstr(str);
	db_putstr(" ");
	db_putstr(str2);
	db_putstr("\n");
	db_putstr(db_strncpy(str2, "Eb\n", 6));
	while (count < 10)
	{
		db_putnbr(str2[count++]);
		db_putstr(" ");
	}
	db_putstr("\n");
	return (0);
}
