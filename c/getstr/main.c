/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:24:55 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/16 12:29:23 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../putstr/db_putstr.h"
#include "db_getstr.h"

int	main(void)
{
	char	str[100];

	db_getstr(str);
	db_putstr(str);
	return (0);
}
