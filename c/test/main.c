/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:09:28 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/09 13:07:14 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../getchar/db_getchar.h"

int	main(void)
{
	int	intt;
	int	*ptr;

	ptr = &intt;
	intt = 46;
	printf("*ptr = %d\n", *ptr);
	*ptr = 54;
	printf("intt = %d\n", intt);
	*ptr = *ptr / 2;
	printf("intt = %d\n", intt);
	printf("a: %d, z: %d, A: %d, Z: %d\n", 'a', 'z', 'A', 'Z');
	return (0);
}
