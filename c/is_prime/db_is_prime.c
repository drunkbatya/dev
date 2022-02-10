/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:05:16 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/30 17:57:44 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	db_is_prime(int nb)
{
	int	count;

	count = 1;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	while (++count < nb)
		if ((nb % count) == 0)
			return (0);
	return (1);
}
