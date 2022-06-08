/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:18:53 by tschlege          #+#    #+#             */
/*   Updated: 2022/06/08 23:55:59 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Wati_Minitalk.h"

int	ft_msglen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	send(int c, int pid, int choice)
{
	int	index;

	index = 30;
	if (choice == 1)
		index = 7;
	while (index >= 0)
	{
		usleep(200);
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
		return (EXIT_FAILURE);
	printf("%d\n", ft_msglen(argv[2]));
	send(ft_msglen(argv[2]), ft_atoi(argv[1]), 42);
	while (argv[2][i])
	{
		send(argv[2][i], ft_atoi(argv[1]), 1);
		i++;
	}
	send(argv[2][i], ft_atoi(argv[1]), 1);
	return (EXIT_FAILURE);
}
