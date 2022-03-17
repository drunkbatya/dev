/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:48:39 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/12 14:56:02 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db_strcmp.h"
#include "../putnbr/db_putnbr.h"
#include "../strcpy/db_strcpy.h"

int	main(void)
{
	char	str1[100];
	char	str2[100];

	db_strcpy(str1, "qwErty");
	db_strcpy(str2, "qwrty");
	db_putnbr(db_strcmp(str1, str2));
	return (0);
}
