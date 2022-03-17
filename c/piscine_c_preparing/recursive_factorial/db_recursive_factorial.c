/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:32:10 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/24 20:55:12 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	db_recursive_factorial(int nb)
{
	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	return (nb * db_recursive_factorial(nb - 1));
}
