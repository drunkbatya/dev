/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:09:07 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/08 15:30:36 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db_strcpy.h"
#include "../putstr/db_putstr.h"

int	main(void)
{
	char	str[100] = "Testiqqqqqqq";
	char	str2[108] = "123";

	db_putstr(str);
	db_putstr(" ");
	db_putstr(str2);
	db_putstr("\n");
	db_strcpy(str2, str);
	db_putstr(str);
	db_putstr(" ");
	db_putstr(str2);
	db_putstr("\n");
	db_putstr(db_strcpy(str2, "Ebbbbaaad\n"));
	return (0);
}
