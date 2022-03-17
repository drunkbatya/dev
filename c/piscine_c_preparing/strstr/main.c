/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:09:50 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/13 14:49:00 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db_strstr.h"
#include "../putstr/db_putstr.h"
#include "../strcpy/db_strcpy.h"

int	main(void)
{
	char	str1[100];
	char	str2[100];
	char	*res;

	db_putstr(db_strcpy(str1, "Test string strahh ddssss"));
	db_putstr("\n");
	db_putstr(db_strcpy(str2, "stra"));
	db_putstr("\n");
	res = db_strstr(str1, str2);
	if (res)
		db_putstr(res);
	else
		db_putstr("Null");
	db_putstr("\n");
	return (0);
}
