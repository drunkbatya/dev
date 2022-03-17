/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:12:29 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/12 14:11:57 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db_print_memory.h"
#include "../strcpy/db_strcpy.h"

int	main(void)
{
	char	arr[100];
	char	*addr;

	addr = &arr[0];
	db_strcpy(addr, "Testingwordmfck");
	db_print_memory(addr, 1);
	return (0);
}
