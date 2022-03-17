/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:37:54 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/12 15:11:07 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	db_strncmp(char	*s1, char *s2, unsigned int n)
{
	int	count;

	count = 0;
	while (s1[count] != '\0' && count < n)
	{
		if (s1[count] > s2[count])
			return (1);
		if (s2[count] > s1[count])
			return (-1);
		count++;
	}
	return (0);
}
