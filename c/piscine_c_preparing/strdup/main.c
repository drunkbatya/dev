/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:49:47 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/02/09 14:11:28 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db_strdup.h"
#include "../putstr/db_putstr.h"
#include "../strcpy/db_strcpy.h"

int	main(void)
{
	char	str[100];
	char	*str2;

	db_putstr(db_strcpy(str, "Suck my fuck"));
	str2 = db_strdup(str);
	db_putstr(str2);
	return (0);
}
