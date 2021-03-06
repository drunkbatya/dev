/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:24:36 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/27 12:39:59 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	db_sqrt(int nb)
{
	int	num;

	num = 2;
	if (nb == 1)
		return (1);
	while (nb >= (num * num))
	{
		if (nb == (num * num))
			return (num);
		num++;
	}
	return (0);
}
