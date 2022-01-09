/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:25:44 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/09 16:03:11 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*db_strupcase(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] >= 'a' && str[count] <= 'z')
			str[count] = str[count] - ('a' - 'A');
		count++;
	}
	return (str);
}
