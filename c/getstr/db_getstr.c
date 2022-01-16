/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_getstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:23:49 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/16 12:31:11 by drunkbaty        ###   ########.fr       */
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

char	*db_getstr(char *buf)
{
	char	ch;

	ch = 0;
	while (ch != '\n' && ch != -1)
	{
		*buf = db_getchar();
		ch = *buf;
		buf++;
	}
	*buf = '\0';
	return (buf);
}
