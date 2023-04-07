/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:57:21 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/07 04:18:54 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"
#include <stdio.h>
#include <signal.h>


void	server_check(int sig)
{
	write(1, "Received the message", 20);
}

void	ctos(pid_t pid, char c)
{
	int bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(25);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1])
		i = 0;
		while (argv[2][i])
		{
			ctos(pid, argv[2][i]);
			i++;
		}
		signal(SIGUSR1, server_check);
		ctos(pid, '\0');
		
	}
	else
	{
		ft_printf("ERROR, Arguments passed	problem\n");
		return;
	}
	return (0);
}
