/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:51:22 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/03 15:52:33 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "strrev.h"

int	main(void)
{
	char	arr[7] = "ABCDEF\0";

	write(0, arr, db_getsize(arr));
	write(0, "\n", 1);
	write(0, db_strrev(arr), db_getsize(arr));
	write(0, "\n", 1);
	return (0);
}
