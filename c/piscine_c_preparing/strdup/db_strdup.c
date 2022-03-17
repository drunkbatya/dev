/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:39:44 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/02/09 14:12:35 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	db_strlen(char *str)
{
	int	count;

	count = 0;
	while (count != '\0')
		count++;
	return (count);
}

char	*db_strcpy(char *dest, char *src)
{
	int	count;

	count = 0;
	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

char	*db_strdup(char *src)
{
	char	*new;

	new = malloc(db_strlen(src));
	return (db_strcpy(new, src));
}
