/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:03:57 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/09 13:41:48 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	db_str_is_alpha(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] < 'A' || str[count] > 'z')
			return (0);
		if (str[count] > 'Z' && str[count] < 'a')
			return (0);
		count++;
	}
	return (1);
}
