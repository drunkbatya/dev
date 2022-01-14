/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:03:42 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/14 19:40:18 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	main(void)
{
	char	buf[100];

	while (buf[0] != -1)
	{
		db_putstr("DrunkShell: ");
		db_getstr(buf);
		if (db_strcmp(buf, "test\n") == 0)
			db_putstr("\033[0;32mTesting in progress\033[0;37m\n");
		else if (db_strlen(buf) != 1)
			db_putstr("\033[0;31mUnknown command..\033[0;37m\n");
	}
	if (buf[0] == -1)
		db_putstr("\033[0;33m\nSee U later :-)\033[0;37m\n");
	return (0);
}
