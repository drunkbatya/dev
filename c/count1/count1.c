/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:20:40 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/06 14:20:17 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <inttypes.h>

int	main(void)
{
	uint32_t	nl;
	uint32_t	space;
	uint32_t	tab;
	uint32_t	sym;
	char		c;

	nl = 0;
	space = 0;
	tab = 0;
	for (sym = 0; (c = getchar()) != EOF; sym++)
	{
		if (c == '\n')
			nl++;
		if (c == ' ')
			space++;
		if (c == '\t')
			tab++;
	}
	printf("Total:\n\tSymbols: %d\n\tSpaces: %d\n\tTabs: %d\n\tLines: %d\nEND\n", sym, space, tab, nl);
	return (0);
}
