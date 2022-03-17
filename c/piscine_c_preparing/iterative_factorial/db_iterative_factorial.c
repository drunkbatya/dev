/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:32:10 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/24 19:59:23 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	db_iterative_factorial(int nb)
{
	int	count;
	int	res;

	if (nb < 0)
		return (0);
	count = nb;
	res = 1;
	while (count)
	{
		res = res * count;
		count--;
	}
	return (res);
}
