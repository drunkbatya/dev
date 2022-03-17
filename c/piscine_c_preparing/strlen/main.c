/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:26:34 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/06 12:45:29 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db_strlen.h"
#include <unistd.h>
#include "../putnbr/db_putnbr.h"

int	main(void)
{
	db_putnbr(db_strlen("Bitch"));
	return (0);
}
