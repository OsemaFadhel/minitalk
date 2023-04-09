/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:57:32 by ofadhel           #+#    #+#             */
/*   Updated: 2023/04/09 19:40:08 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	stoc(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	word;

	(void)context;
	if (sig == SIGUSR1)
		word += 1 << bit;
	bit++;
	if (bit == 8)
	{
		write (1, &word, 1);
		if (word == '\0')
		{
			kill(info->si_pid, SIGUSR2);
		}
		word = 0;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	act;

	(void)argv;
	if (argc != 1)
	{
		printf("ERROR, No arguments needed!\n");
		return (1);
	}
	ft_printf("PID : ");
	pid = getpid();
	ft_printf("%d\n", pid);
	act.sa_sigaction = stoc;
	act.sa_flags = 0;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
	}
	return (0);
}
