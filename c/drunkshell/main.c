/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:03:42 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/24 10:30:21 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libdrunk/includes/libdrunk.h"
#include "drunkshell.h"
#include "colors.h"

int	main(void)
{
	char	buf[100];

	while (buf[0] != EOF)
	{
		db_putstr("DrunkShell :-( ");
		db_getstr(buf);
		db_strnlcut(buf);
		//drunkshell_parsecmd(buf);
		drunkshell_exec(buf);
	}
	if (buf[0] == EOF)
		db_putstr("\033[0;33m\nSee U later :-)"NC"\n");
	return (0);
}
