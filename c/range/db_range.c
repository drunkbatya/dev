/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:12:17 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/02/10 16:09:36 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*db_range(int min, int max)
{
	int	*arr;
	int	count;

	if (min >= max)
		return ((void *)0);
	arr = malloc((max - min) * sizeof(int));
	count = 0;
	while (count < (max - min))
	{
		arr[count] = min + count;
		count++;
	}
	return (arr);
}
