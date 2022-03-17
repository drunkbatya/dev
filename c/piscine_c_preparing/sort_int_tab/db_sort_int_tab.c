/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:08:25 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/08 14:23:59 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	db_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	db_sort_int_tab(int *tab, int size)
{
	int	count1;
	int	count2;

	count1 = 0;
	while (count1 < size - 1)
	{
		count2 = 0;
		while (count2 < size - 1)
		{
			if (tab[count2] > tab[count2 + 1])
				db_swap(&tab[count2], &tab[count2 + 1]);
			count2++;
		}
		count1++;
	}
}
