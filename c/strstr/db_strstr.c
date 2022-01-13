/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:01:23 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/13 14:48:48 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	db_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*db_strstr(char *str, char *to_find)
{
	int	count;
	int	count2;
	int	countf;
	int	found_len;
	int	to_find_len;

	count = 0;
	to_find_len = db_strlen(to_find);
	while (str[count] != '\0')
	{
		countf = 0;
		found_len = 0;
		count2 = count;
		while (str[count2] == to_find[countf])
		{
			found_len++;
			count2++;
			countf++;
		}
		if (found_len == to_find_len)
			return (str + count);
		count++;
	}
	return ((char *)0);
}
