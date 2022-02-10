/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:28:50 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/02/10 16:09:52 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../putnbr/db_putnbr.h"
#include "db_range.h"

int	main(void)
{
	int	*arr;
	int	size;
	int	count;

	size = 20;
	count = 0;
	arr = db_range(140, 14);
	while (count < size)
	{
		db_putnbr(arr[count]);
		count++;
	}
	return (0);
}
