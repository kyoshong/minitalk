/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:58:13 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/02 22:56:13 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <sys/signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
//utils

struct sigaction s_siga;

typedef struct s_info
{
	int		client_pid;
	int		*msg;
}				t_info;

char		*ft_itoa(int n);
size_t		ft_strlen(char const *str);

#endif
