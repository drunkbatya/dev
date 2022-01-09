/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:53:31 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/09 15:21:50 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	db_str_is_printable(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] >= 0x00 && str[count] <= 0x1F)
			return (0);
		if (str[count] > 0x7E)
			return (0);
		count++;
	}
	return (1);
}
