/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drunklib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:38:37 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/16 12:42:46 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRUNKLIB_H
# define DRUNKLIB_H

int		db_strcmp(char	*s1, char *s2);
int		db_strlen(char *str);
void	db_putchar(char c);
char	db_getchar(void);
char	*db_getstr(char *buf);
void	db_putstr(char *str);
void	db_swap(int *a, int *b);
#endif
