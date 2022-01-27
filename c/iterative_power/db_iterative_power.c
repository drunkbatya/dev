/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:03:58 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/24 21:19:29 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	db_iterative_power(int nb, int power)
{
	int	res;

	if (nb == 0 & power == 0)
		return (1);
	if (power < 0)
		return (0);
	res = nb;
	while (power - 1)
	{
		res = res * nb;
		power--;
	}
	return (res);
}
