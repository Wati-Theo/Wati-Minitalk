/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:18:46 by tschlege          #+#    #+#             */
/*   Updated: 2022/06/15 18:37:35 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Wati_Minitalk.h"

t_msg	g_msg;

void	binary_to_ascii(int bit)
{
	g_msg.byte += bit << g_msg.count;
	g_msg.count++;
	if (g_msg.count == 8)
	{
		g_msg.msg[g_msg.index] = g_msg.byte;
		g_msg.index++;
		g_msg.count = 0;
		if (!g_msg.byte)
		{
			ft_putstr((char *)g_msg.msg);
			free(g_msg.msg);
			g_msg.msg_len = 0;
			g_msg.bit_recept = 0;
			g_msg.index = 0;
		}
		g_msg.byte = 0;
	}
}

void	siga(int bit)
{
	while (g_msg.holder)
		usleep(1);
	g_msg.holder = 1;
	if (g_msg.bit_recept < 30)
	{
		g_msg.msg_len += bit << g_msg.bit_recept;
		g_msg.bit_recept++;
	}
	else if (g_msg.bit_recept == 30)
	{
		g_msg.msg = malloc(sizeof(char) * (g_msg.msg_len + 1));
		g_msg.bit_recept++;
	}
	else
	{
		binary_to_ascii(bit);
	}
	g_msg.holder = 0;
}

void	on_sigusr1(int sig)
{
	siga(0);
	if (sig)
		;
}

void	on_sigusr2(int sig)
{
	siga(1);
	if (sig)
		;
}

int	main(int argc, char *argv[])
{
	if (argc || argv)
		;
	g_msg.msg = NULL;
	g_msg.holder = 0;
	g_msg.count = 0;
	g_msg.byte = 0;
	g_msg.bit_recept = 0;
	g_msg.msg_len = 0;
	g_msg.index = 0;
	signal(SIGUSR1, &on_sigusr1);
	signal(SIGUSR2, &on_sigusr2);
	ft_putstr("LE PID EST ");
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		usleep(1);
	return (0);
}
