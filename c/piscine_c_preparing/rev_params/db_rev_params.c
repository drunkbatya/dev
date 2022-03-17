/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:36:06 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/20 17:40:30 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	db_putchar(char c)
{
	write(1, &c, 1);
}

void	db_putstr(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		db_putchar(str[count]);
		count++;
	}
}

int	main(int argv, char *argc[])
{
	int	count;

	count = argv - 1;
	while (count)
	{
		db_putstr(argc[count]);
		db_putstr("\n");
		count--;
	}
	return (0);
}
