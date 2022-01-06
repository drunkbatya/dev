/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:31:30 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/06 14:03:15 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db_getchar.h"
#include "../putchar/db_putchar.h"
#include <unistd.h>

int	main(void)
{
	char	c;

	c = db_getchar();
	db_putchar(c);
	return (0);
}
