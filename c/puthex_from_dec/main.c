/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:59:58 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/10 20:19:02 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "db_puthex_from_dec.h"

int	main(void)
{
	long	num;

	num = 9988771244;
	db_puthex_from_dec(num);
	return (0);
}
