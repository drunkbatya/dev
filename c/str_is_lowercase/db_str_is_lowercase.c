/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:35:22 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/09 14:36:18 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	db_str_is_lowercase(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] < 'a' || str[count] > 'z')
			return (0);
		count++;
	}
	return (1);
}
