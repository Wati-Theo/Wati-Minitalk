/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:18:53 by tschlege          #+#    #+#             */
/*   Updated: 2022/06/07 22:02:31 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Wati_Minitalk.h"

void	send(unsigned char c, int pid)
{
	int	index;

	index = 7;
	while (index >= 0)
	{
		usleep(80);
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
