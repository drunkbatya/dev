/* ************************************************************************** */
/*									    */
/*							:::      ::::::::   */
/*   db_strjoin.c                                       :+:      :+:    :+:   */
/*						    +:+ +:+	 +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+	*/
/*						+#+#+#+#+#+   +#+	   */
/*   Created: 2022/02/10 16:56:01 by drunkbaty	 #+#    #+#	     */
/*   Updated: 2022/02/10 19:37:13 by drunkbaty        ###   ########.fr       */
/*									    */
/* ************************************************************************** */

#include <stdlib.h>

int	db_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*db_strcat(char *dest, char *src)
{
	int	count;
	int	dest_len;

	count = 0;
	dest_len = db_strlen(dest);
	while (src[count] != '\0')
	{
		dest[dest_len + count] = src[count];
		count++;
	}
	dest[dest_len + count] = '\0';
	return (dest);
}

char	*db_strjoin(int size, char **strs, char *sep)
{
	char	*out_str;
	int		count;
	int		out_str_size;

	count = 0;
	out_str_size = 0;
	while (count < size)
	{
		out_str_size += db_strlen(strs[count]);
		count++;
	}
	out_str_size += db_strlen(sep) * (size - 1);
	out_str = malloc((out_str_size + 1) * sizeof(char));
	if (out_str == (void *)0)
		return ((void *)0);
	count = 0;
	while (count < size)
	{
		db_strcat(out_str, strs[count]);
		if (count < size - 1)
			db_strcat(out_str, sep);
		count++;
	}
	return (out_str);
}
