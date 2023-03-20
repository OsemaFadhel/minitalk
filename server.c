/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:57:32 by ofadhel           #+#    #+#             */
/*   Updated: 2023/03/20 18:43:45 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 1)
	{
		printf("ERROR, No arguments needed!\n";
		return ;
	}
	pid = getpid();
	printf("%d\n", pid);
}
