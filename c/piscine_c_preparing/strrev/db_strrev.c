/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:52:38 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/06 13:12:56 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "db_strrev.h"

int	db_getsize(char *array)
{
	int	size;

	size = 0;
	while (array[size] != '\0')
		size++;
	return (size);
}

char	*db_strrev(char *array)
{
	int	end;
	int	start;
	int	temp;

	start = 0;
	end = db_getsize(array) - 1;
	while (start < end)
	{
		temp = array[end];
		array[end] = array[start];
		array[start] = temp;
		end--;
		start++;
	}
	return (array);
}
