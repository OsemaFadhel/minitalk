/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:57:21 by ofadhel           #+#    #+#             */
/*   Updated: 2023/03/20 19:01:22 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <signal.h>

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		printf("ERROR, Arguments passed	problem\n");
		return;
	}
	pid = ft_atoi()/* here we should store the pid 
		remember atoi cause its passed as a char
		but we need it as a int*/;
	i = 0;
	while (argv[2])
	{
		/*here i think ill use it to send
		 * the string to server char by char*/;
		i++;
	}
	return (0);
}
