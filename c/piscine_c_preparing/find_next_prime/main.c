/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:06:50 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/30 18:11:34 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../putnbr/db_putnbr.h"
#include "db_find_next_prime.h"

int	main(void)
{
	db_putnbr(db_find_next_prime(41));
	return (0);
}
