/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:36:46 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/24 20:55:39 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db_recursive_factorial.h"
#include "../putnbr/db_putnbr.h"

int	main(void)
{
	db_putnbr(db_recursive_factorial(5));
	return (0);
}
