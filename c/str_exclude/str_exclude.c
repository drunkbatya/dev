/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_exclude.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:17:31 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/05 19:29:38 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	db_strexcl(char one[], char two[])
{
	int	orig_str_char_count;
	int	new_str_char_count;
	int	two_str_char_count;
	int	skip_flag;

	orig_str_char_count = 0;
	new_str_char_count = 0;
	while (one[orig_str_char_count] != '\0')
	{
		two_str_char_count = 0;
		while (two[two_str_char_count] != '\0')
		{
			skip_flag = 1;
			if (one[orig_str_char_count] == two[two_str_char_count++])
				break ;
			skip_flag = 0;
		}
		if (!skip_flag)
			one[new_str_char_count++] = one[orig_str_char_count];
		orig_str_char_count++;
	}
	one[new_str_char_count] = '\0';
}
