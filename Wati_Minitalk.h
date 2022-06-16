/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati_Minitalk.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:51:16 by tschlege          #+#    #+#             */
/*   Updated: 2022/06/16 14:46:54 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WATI_MINITALK_H
# define WATI_MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_msg {
	unsigned char	*msg;
	unsigned char	byte;
	int				holder;
	int				count;
	int				msg_len;
	int				bit_recept;
	int				index;
}	t_msg;

extern t_msg	g_msg;

void	ft_putnbr(int n);
size_t	ft_strlen(unsigned char *s);
void	ft_putstr(char *s);
int		ft_isdigit(int c);
#endif