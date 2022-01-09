/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:25:44 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/09 16:14:04 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*db_strlowcase(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] >= 'A' && str[count] <= 'Z')
			str[count] = str[count] + ('a' - 'A');
		count++;
	}
	return (str);
}
