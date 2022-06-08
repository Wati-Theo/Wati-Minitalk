/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wati-Theo <wati-theo@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:18:53 by tschlege          #+#    #+#             */
/*   Updated: 2022/06/08 16:29:37 by Wati-Theo        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Wati_Minitalk.h"

void	send(unsigned char c, int pid)
{
	int	index;

	index = 7;
	while (index >= 0)
	{
		usleep(800);
		if (c & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c >>= 1;
		index--;
	}

}

int	main(int argc, char *argv[])
{
	int		i;

	i = 0;
	if (argc != 3)
		return (1);
	while (argv[2][i])
	{
		send(argv[2][i], ft_atoi(argv[1]));
		i++;
	}
}
