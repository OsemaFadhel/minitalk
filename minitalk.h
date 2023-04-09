/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:30:27 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/09 19:01:49 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int         ft_printf(const char *format, ...);
int         ft_putchar(char c);
int         ft_putstr(char *str);
int         ft_pointer(unsigned long ptr);
int         ft_hexlower(unsigned int nb);
int         ft_hexupper(unsigned int nb);
int         ft_putunbr(unsigned int nb);
int         ft_putnbr(int nb);

#endif