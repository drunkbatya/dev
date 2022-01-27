/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drunkshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:39:08 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/24 10:03:42 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRUNKSHELL_H
# define DRUNKSHELL_H
# ifndef EOF
#  define EOF -1
# endif

int	drunkshell_parsecmd(char *buf);
void	drunkshell_exec(char *buf);
#endif
