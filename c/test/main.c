/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:09:28 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/08 00:14:47 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../getchar/db_getchar.h"

int	main(void)
{
	int		i;
	char	ch;

	i = 0;
	while (i++ < 5)
	{
		ch = db_getchar();
		printf("%d\n", ch);
	}
	return (0);
}
