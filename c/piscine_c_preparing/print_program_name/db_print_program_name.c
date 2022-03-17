/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:22:09 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/20 17:28:47 by drunkbaty        ###   ########.fr       */
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
	db_putstr(argc[0]);
	return (0);
}
