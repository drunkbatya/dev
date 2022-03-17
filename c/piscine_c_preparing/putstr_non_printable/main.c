/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:14:12 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/10 13:56:47 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db_putstr_non_printable.h"
#include "../strcpy/db_strcpy.h"

int	main(void)
{
	char	str1[100];
	char	str2[100];

	db_strcpy(str1, "Test\t\b\n\n string!\nTestTTggt");
	db_putstr_non_printable(str1);
	return (0);
}
