/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati_Minitalk.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:51:16 by tschlege          #+#    #+#             */
/*   Updated: 2022/06/09 01:21:27 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WATI_MINITALK_H
# define WATI_MINITALK_H

# include <sys/types.h>
# include <signal.h>
# include <stdio.h>
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

size_t			ft_strlen(unsigned char *s);
int				ft_atoi(const char *str);
unsigned char	*ft_el_famoso(unsigned char *msg, unsigned char byte);
#endif