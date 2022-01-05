/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:50:21 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/05 20:17:50 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	db_putchar(char c)
{
	write(1, &c, 1);
}

void	db_putstr(char *str)
{
	int	count;

	count = 0;
	while (*(str + count) != '\0')
		db_putchar(*(str + count++));
}
