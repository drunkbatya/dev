/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:13:23 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/16 14:39:55 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	db_atoi(char *str)
{
	int	res;
	int	count;
	int	change_sign;

	res = 0;
	count = 0;
	change_sign = 0;
	while (str[count] != '\0')
	{
		if (str[count] == '-' && res == 0)
			change_sign = 1;
		if (str[count] >= '0' && str[count] <= '9')
			res = res * 10 + str[count] - '0';
		else if (res != 0)
			break ;
		count++;
	}
	if (change_sign)
		res = -res;
	return (res);
}
