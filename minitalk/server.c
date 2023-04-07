/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:57:32 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/07 04:18:53 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "include/minitalk.h""

void	stoc(int sig)
{
	int	
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 1)
	{
		ft_printf("ERROR, No arguments needed!\n";
		return ;
	}
	pid = getpid();
	ft_printf("%d\n", pid);
	return (0);
}
