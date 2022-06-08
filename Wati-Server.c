/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wati-Theo <wati-theo@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:18:46 by tschlege          #+#    #+#             */
/*   Updated: 2022/06/08 15:59:23 by Wati-Theo        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Wati_Minitalk.h"

void	siga(int bit)
{
	static unsigned char	msg = 0;
	static int				count = 0;

	msg += bit << count;
	count++;
	if (count == 8)
	{
		write(1, &msg, 1);
		msg = 0;
		count = 0;
	}
}

void	on_sigusr1(int sig)
{
	siga(0);
}

void	on_sigusr2(int sig)
{
	siga(1);
}

int	main(int argc, char *argv[])
{
	signal(SIGUSR1, &on_sigusr1);
	signal(SIGUSR2, &on_sigusr2);
	printf("LE PID EST %d\n", getpid());
	while (1)
		sleep(1);
	return (0);
}
