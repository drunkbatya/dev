/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:49:40 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/02/10 16:13:33 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	db_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	count;

	if (min >= max)
	{
		*range = (void *)0;
		return (0);
	}
	arr = malloc((max - min) * sizeof(int));
	if (arr == ((void *)0))
		return (-1);
	count = 0;
	while (count < (max - min))
	{
		arr[count] = min + count;
		count++;
	}
	*range = arr;
	return (max - min);
}
