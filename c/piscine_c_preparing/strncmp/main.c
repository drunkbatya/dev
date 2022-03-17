/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:48:39 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/12 15:11:35 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db_strncmp.h"
#include "../putnbr/db_putnbr.h"
#include "../strcpy/db_strcpy.h"

int	main(void)
{
	char	str1[100];
	char	str2[100];

	db_strcpy(str1, "qwErty");
	db_strcpy(str2, "qwrty");
	db_putnbr(db_strncmp(str1, str2, 2));
	return (0);
}
