/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:20:28 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/24 21:59:26 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	db_recursive_power(int nb, int power)
{
	if (nb == 0 && power == 0)
		return (1);
	if (power == 1)
		return (nb);
	if (power <= 0)
		return (0);
	return (nb * db_recursive_power(nb, power - 1));
}
