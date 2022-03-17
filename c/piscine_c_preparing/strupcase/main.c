/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:33:32 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/09 16:10:44 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../strcpy/db_strcpy.h"
#include "../putstr/db_putstr.h"
#include "db_strupcase.h"

int	main(void)
{
	char	str1[100];
	char	str2[100];

	db_strcpy(str1, "Test string bitCH\n");
	db_strcpy(str2, "Test\n");
	db_putstr(db_strupcase(str1));
	db_putstr(db_strupcase(str2));
	return (0);
}
