/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:17:15 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/09 17:01:24 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	db_lower(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		*c = *c + ('a' - 'A');
	return (*c);
}

char	db_upper(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = *c - ('a' - 'A');
	return (*c);
}

char	*db_strcapitalize(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (count == 0)
			db_upper(&str[count]);
		else if (str[count] == ' ')
		{
			count++;
			db_upper(&str[count]);
			if (str[count] == ' ')
				continue ;
		}
		else
			db_lower(&str[count]);
		count++;
	}
	return (str);
}
