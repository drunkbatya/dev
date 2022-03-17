/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:41:33 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/19 19:28:01 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	db_strcmp_hard(char *s1, char *s2)
{
	int	count;

	count = 0;
	while (s1[count] != '\0')
	{
		if (s1[count] != s2[count])
			return (1);
		count++;
	}
	if (s1[count] != s2[count])
		return (1);
	return (0);
}

void	db_atoi_in_base(char *str, int base, int *res)
{
	int	count;
	int	change_sign;

	count = 0;
	change_sign = 0;
	while (str[count] != '\0')
	{
		if (str[count] == '-' && *res == 0)
			change_sign = 1;
		if (str[count] >= '0' && str[count] <= '9')
			*res = *res * base + str[count] - '0';
		else if (str[count] >= 'A' && str[count] <= 'F')
			*res = *res * base + str[count] - 'A' + 10;
		else if (str[count] >= 'a' && str[count] <= 'f')
			*res = *res * base + str[count] - 'a' + 10;
		else if (*res != 0)
			break ;
		count++;
	}
	if (change_sign)
		*res = -(*res);
}

int	db_atoi_base(char *str, char *base)
{
	int	res;

	res = 0;
	if (db_strcmp_hard(base, "0123456789") == 0)
		db_atoi_in_base(str, 10, &res);
	else if (db_strcmp_hard(base, "0123456789ABCDEF") == 0)
		db_atoi_in_base(str, 16, &res);
	else if (db_strcmp_hard(base, "01") == 0)
		db_atoi_in_base(str, 2, &res);
	else if (db_strcmp_hard(base, "poneyvif") == 0)
		db_atoi_in_base(str, 8, &res);
	return (res);
}
