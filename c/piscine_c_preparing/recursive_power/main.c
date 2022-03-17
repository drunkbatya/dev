/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:39:15 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/24 21:59:36 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../putnbr/db_putnbr.h"
#include "db_recursive_power.h"

int	main(void)
{
	db_putnbr(db_recursive_power(4, 4));
	return (0);
}
