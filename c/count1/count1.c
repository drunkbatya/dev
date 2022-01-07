/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:20:40 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/08 00:10:31 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <inttypes.h>
#include "../putstr/db_putstr.h"
#include "../putnbr/db_putnbr.h"
#include "../getchar/db_getchar.h"

void	print_stat(int sym, int nl, int space, int tab)
{
	db_putstr("Total:\n\tSymbols: ");
	db_putnbr(sym);
	db_putstr("\n\tSpaces: ");
	db_putnbr(space);
	db_putstr("\n\tTabs: ");
	db_putnbr(tab);
	db_putstr("\n\tLines: ");
	db_putnbr(nl);
	db_putstr("\nEND\n");
}

int	main(void)
{
	int		nl;
	int		space;
	int		tab;
	int		sym;
	char	ch;

	nl = 0;
	space = 0;
	tab = 0;
	sym = -1;
	while (ch != EOF)
	{
		ch = db_getchar();
		if (ch == '\n')
			nl++;
		else if (ch == ' ')
			space++;
		else if (ch == '\t')
			tab++;
		sym++;
	}
	print_stat(sym, nl, space, tab);
	return (0);
}
