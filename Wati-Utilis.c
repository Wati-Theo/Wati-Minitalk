/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Utilis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:19:03 by tschlege          #+#    #+#             */
/*   Updated: 2022/06/08 22:57:12 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Wati_Minitalk.h"

size_t	ft_strlen(unsigned char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

unsigned char	*ft_el_famoso(unsigned char *msg, unsigned char byte)
{
	unsigned char	*str;
	int				i;

	i = 0;
	if (!msg && byte)
	{
		str = malloc(2 * sizeof(char));
		str[0] = byte;
		str[1] = 0;
	}
	else
	{
		str = malloc((ft_strlen(msg) + 1) * sizeof(char));
		while (msg[i])
		{
			str[i] = msg[i];
			i++;
		}
		str[i] = byte;
		str[++i] = 0;
	}
	return (str);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

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
