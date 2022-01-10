/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:09:28 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/10 15:04:50 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../getchar/db_getchar.h"

int	main(void)
{
	int		intt;
	int		*adr;
	void		*addr;

	intt = 46;
	addr = &intt;
        adr = (int *)addr;
	printf("Size of ptr: %ld\n", sizeof(adr));
	printf("Value: %d\n", *adr);
	printf("Address: %lu\n", (unsigned long)&adr);
	printf("Address: %lu\n", (unsigned long)&adr);
	printf("Address HEX: %p\n", &adr);
	return (0);
}
