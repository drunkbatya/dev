/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:04:01 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/09 12:54:29 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*db_strncpy(char *dest, char *src, unsigned int n)
{
	int	count;

	count = 0;
	while (src[count] != '\0' && count < n)
	{
		dest[count] = src[count];
		count++;
	}
	while (count < n)
		dest[count++] = '\0';
	return (dest);
}
