/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_strnlcut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:24:33 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/24 10:28:19 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	db_strnlcut(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] == '\n')
			str[count] = '\0';
		count++;
	}
}
