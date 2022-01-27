/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:28:52 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/27 11:58:21 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	db_fibonacci_it(int index)
{
	int	num1;
	int	num2;
	int	temp;

	num1 = 0;
	num2 = 1;
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	while (index - 1)
	{
		temp = num1;
		num1 = num2;
		num2 = num1 + temp;
		index--;
	}
	return (num2);
}

int	db_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (db_fibonacci(index - 1) + db_fibonacci(index - 2));
}
