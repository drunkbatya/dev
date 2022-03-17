/* ************************************************************************** */
/*									    */
/*							:::      ::::::::   */
/*   db_sort_params.c                                   :+:      :+:    :+:   */
/*						    +:+ +:+	 +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+	*/
/*						+#+#+#+#+#+   +#+	   */
/*   Created: 2022/01/20 17:48:05 by drunkbaty	 #+#    #+#	     */
/*   Updated: 2022/02/09 13:03:36 by drunkbaty        ###   ########.fr       */
/*									    */
/* ************************************************************************** */

#include <unistd.h>

void	db_putstr(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		write(1, &str[count], 1);
		count++;
	}
}

void	db_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	db_strcmp(char *s1, char *s2)
{
	int	count;

	count = 0;
	while (s1[count] != '\0')
	{
		if (s1[count] > s2[count])
			return (1);
		if (s2[count] > s1[count])
			return (-1);
		count++;
	}
	return (0);
}

void	db_sort_str_arr(char *tab[], int size)
{
	int	count1;
	int	count2;

	count1 = 0;
	while (count1 < size - 1)
	{
		count2 = 0;
		while (count2 < size - 1)
		{
			if (db_strcmp(tab[count2], tab[count2 + 1]) > 0)
				db_swap(&tab[count2], &tab[count2 + 1]);
			count2++;
		}
		count1++;
	}
}

int	main(int argc, char *argv[])
{
	int	count;

	count = 1;
	db_sort_str_arr(argv, argc);
	while (count < argc)
	{
		db_putstr(argv[count]);
		db_putstr("\n");
		count++;
	}
	return (0);
}
