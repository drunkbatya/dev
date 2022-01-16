/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:40:02 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/16 13:45:10 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "../libdrunk/includes/libdrunk.h"

void	drunkshell_test(void)
{
	db_putstr(GREEN"Testing in progress"NC"\n");
}

void	drunkshell_unknown(void)
{
	db_putstr(RED"Unknown command.."NC"\n");
}
