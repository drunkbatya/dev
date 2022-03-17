/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:34:35 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/06 12:39:10 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "db_ft_ultimate.h"
#include "../putchar/db_putchar.h"
#include "../putnbr/db_putnbr.h"

int	main(void)
{
	int	test;
	int	*testt;
	int	**testtt;
	int	***testttt;
	int	****testtttt;
	int	*****testttttt;
	int	******testtttttt;
	int	*******testttttttt;
	int	********testtttttttt;

	testt = &test;
	testtt = &testt;
	testttt = &testtt;
	testtttt = &testttt;
	testttttt = &testtttt;
	testtttttt = &testttttt;
	testttttttt = &testtttttt;
	testtttttttt = &testttttttt;
	db_ft_ultimate(&testtttttttt);
	db_putnbr(test);
	return (0);
}
