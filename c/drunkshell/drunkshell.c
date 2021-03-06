/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drunkshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:37:14 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/24 10:36:56 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libdrunk/includes/libdrunk.h"
#include "commands.h"
#include "unistd.h"

int	drunkshell_parsecmd(char *buf)
{
	if (db_strcmp(buf, "test\n") == 0)
		drunkshell_test();
	else if (db_strlen(buf) != 1)
	{
		drunkshell_unknown();
		return (1);
	}
	return (0);
}

void	drunkshell_exec(char *buf)
{
	execlp(buf, "", NULL);
	return;
}
