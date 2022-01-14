/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:26:36 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/14 19:42:38 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	db_putchar(char c)
{
	write(1, &c, 1);
}

void	db_putstr(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		db_putchar(str[count++]);
}

char	db_getchar(void)
{
	int		size;
	char	ch;

	size = read(0, &ch, 1);
	if (size <= 0)
		ch = -1;
	return (ch);
}

char	*db_getstr(char *buf)
{
	char	ch;

	ch = 0;
	while (ch != '\n' && ch != -1)
	{
		*buf = db_getchar();
		ch = *buf;
		buf++;
	}
	*buf = '\0';
	return (buf);
}

int	db_strcmp(char	*s1, char *s2)
{
	int	count;

	count = 0;
	while (s1[count] != '\0')
	{
		if (s1[count] > s2[count])
			return (1);
		if (s2[count] > s1[count])
			return (-1);
		count++;
	}
	return (0);
}

int	db_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}
