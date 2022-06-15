/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:18:53 by tschlege          #+#    #+#             */
/*   Updated: 2022/06/15 18:38:04 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Wati_Minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	neg;

	i = 0;
	res = 0;
	neg = 1;
	while (str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * neg);
}

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
		usleep(45);
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
	send(ft_msglen(argv[2]), ft_atoi(argv[1]), 42);
	while (argv[2][i])
	{
		send(argv[2][i], ft_atoi(argv[1]), 1);
		i++;
	}
	send(argv[2][i], ft_atoi(argv[1]), 1);
	return (EXIT_FAILURE);
}
