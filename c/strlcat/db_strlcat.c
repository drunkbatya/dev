/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:54:43 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/13 16:09:25 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	db_strlen(char *str)
{
	unsigned int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

unsigned int	db_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	count;
	unsigned int	cur_dest_len;

	cur_dest_len = db_strlen(dest);
	count = 0;
	while (src[count] != '\0' && (count + cur_dest_len) < size)
	{
		dest[count + cur_dest_len] = src[count];
		count++;
	}
	dest[count + cur_dest_len] = '\0';
	return (count + cur_dest_len);
}
