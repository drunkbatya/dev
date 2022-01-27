/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdrunk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:30:59 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/24 10:28:01 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBDRUNK_H
# define LIBDRUNK_H

int		db_strcmp(char	*s1, char *s2);
int		db_strlen(char *str);
void	db_putchar(char c);
char	db_getchar(void);
char	*db_getstr(char *buf);
void	db_putstr(char *str);
void	db_swap(int *a, int *b);
void	db_strnlcut(char *str);
#endif
