/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:25:17 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/07 23:56:33 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	db_getchar(void)
{
	int		size;
	char	ch;

	size = read(0, &ch, 1);
	if (size <= 0)
		ch = -1;
	return (ch);
}
