/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:53:31 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/09 15:02:26 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	db_str_is_uppercase(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] < 'A' || str[count] > 'Z')
			return (0);
		count++;
	}
	return (1);
}
