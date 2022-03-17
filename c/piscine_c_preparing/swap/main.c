/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:23:27 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/04 17:26:57 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "db_swap.h"

int	main(void)
{
	int	one;
	int	two;

	one = 10;
	two = 45;
	printf("one: %d, two: %d\n", one, two);
	db_swap(&one, &two);
	printf("one: %d, two: %d\n", one, two);
	return (0);
}
