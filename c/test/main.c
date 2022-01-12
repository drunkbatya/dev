/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:09:28 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/12 13:33:30 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../getchar/db_getchar.h"
#include "../strcpy/db_strcpy.h"

int	main(void)
{
	char	arr[100];
	char	*addr;

	addr = &arr[0];
	db_strcpy(arr, "Testingwordmfck");
	printf("Size of ptr: %ld\n", sizeof(addr));
	while (*addr != '\0')
	{
		printf("______\n");
		printf("Address: %lu\n", (unsigned long)addr);
		printf("Address HEX: %p\n", addr);
		printf("Value: %d\n", *addr);
		printf("Sym: %c\n", *addr);
		printf("______\n");
		addr++;
	}
	return (0);
}
