/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:12:29 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/10 14:21:07 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db_print_memory.h"

int	main(void)
{
	int	*nptr;
	int	num;

	num = 10;
	nptr = &num;
	db_print_memory(nptr, 1);
	return (0);
}