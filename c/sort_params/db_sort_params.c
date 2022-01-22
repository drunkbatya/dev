/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:48:05 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/20 19:08:55 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	db_putchar(char c)
{
	write(1, &c, 1);
}

void	db_putstr(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		db_putchar(str[count]);
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

void	db_sort_str_arr(char **argv, int size)
{
	int		count1;
	int		count2;
	char	*temp;

	//argv[1][0] = argv[2][0];
	//return;
	count1 = 0;
	while (count1 < size - 1)
	{
		count2 = 0;
		while (count2 < size - 1)
		{
			if (argv[count2][0] > argv[count2 + 1][0])
			{
				temp = argv[count2];
				argv[count2] = argv[count2 + 1];
				argv[count2 + 1] = temp;
			}
			// TODO: how send arguments to function
				//db_swap(&argv[count2], &argv[count2 + 1]);
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
