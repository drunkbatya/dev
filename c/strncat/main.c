/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:45:46 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/12 17:56:37 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db_strncat.h"
#include "../strcpy/db_strcpy.h"
#include "../putstr/db_putstr.h"

int	main(void)
{
	char	str1[100];
	char	str2[100];

	db_putstr(db_strcpy(str1, "Test string!"));
	db_putstr("\n");
	db_putstr(db_strcpy(str2, "Second mthfc string.."));
	db_putstr("\n");
	db_putstr(db_strncat(str2, str1, 1));
	db_putstr("\n");
	return (0);
}
