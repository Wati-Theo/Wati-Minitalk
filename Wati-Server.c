/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:18:46 by tschlege          #+#    #+#             */
/*   Updated: 2022/06/07 22:03:35 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Wati_Minitalk.h"

void	siga(int bit)
{
	static unsigned char	msg = 0;
	static int				count = 0;

	printf("c: %d, msg: %d, b: %d\n", count, msg, bit);
	msg += bit << count;
	count++;
	if (count == 8)
	{
		printf("\n%c\n", msg);
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
