/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:48:55 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/06 15:24:43 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	db_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	count;

	count = -1;
	while (count++ < size--)
	{
		temp = tab[size];
		tab[size] = tab[count];
		tab[count] = temp;
	}
}
