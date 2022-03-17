/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:30:00 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/09 17:02:07 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../strcpy/db_strcpy.h"
#include "../putstr/db_putstr.h"
#include "db_strcapitalize.h"

int	main(void)
{
	char	str1[100];
	char	str2[100];

	db_strcpy(str1, "Testi string bitCH 22ffcFgr fv4FE34\n");
	db_strcpy(str2, "Test\n");
	db_putstr(db_strcapitalize(str1));
	db_putstr(db_strcapitalize(str2));
	return (0);
}
