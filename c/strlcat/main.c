/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:53:18 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/13 16:14:16 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db_strlcat.h"
#include "../putstr/db_putstr.h"
#include "../strcpy/db_strcpy.h"

int	main(void)
{
	char	str[100];
	char	str2[108];
	char	res;

	db_putstr(db_strcpy(str, "Test first sgtring"));
	db_putstr(" ");
	db_putstr(db_strcpy(str2, "sEconD STring"));
	db_putstr(str);
	db_putstr("\n");
	db_strlcat(str2, str, 25);
	db_putstr("\n");
	db_putstr(str2);
	db_putstr("\n");
	return (0);
}
