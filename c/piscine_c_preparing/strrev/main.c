/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:51:22 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/06 13:14:38 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "db_strrev.h"
#include "../putstr/db_putstr.h"

int	main(void)
{
	char	arr[7] = "ABCDEF\0";

	db_putstr(arr);
	db_putstr("\n");
	db_putstr(db_strrev(arr));
	db_putstr("\n");
	return (0);
}
