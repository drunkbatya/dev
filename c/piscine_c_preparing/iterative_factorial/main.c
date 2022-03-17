/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:36:46 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/24 19:59:11 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db_iterative_factorial.h"
#include "../putnbr/db_putnbr.h"

int	main(void)
{
	db_putnbr(db_iterative_factorial(4));
	return (0);
}
