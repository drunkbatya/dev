/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:09:01 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/02/10 19:38:05 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db_strjoin.h"
#include "../strcpy/db_strcpy.h"
#include <unistd.h>

void	db_putstr_local(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		write(1, &str[count], 1);
		count++;
	}
}

int	main(char argc, char **argv)
{
	char	*str;
	char	sep[10];

	db_strcpy(sep, ":-)");
	str = db_strjoin(argc - 1, argv + 1, sep);
	db_putstr_local(str);
	return (0);
}
