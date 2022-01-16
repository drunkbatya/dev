/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:50:21 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/16 13:12:50 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libdrunk.h"

void	db_putstr(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		db_putchar(str[count++]);
}
