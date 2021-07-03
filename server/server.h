/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:58:13 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/04 02:22:25 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <sys/signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

struct sigaction s_siga_zero;
struct sigaction s_siga_one;

typedef struct s_info
{
	int		msg;
	int		check;
}				t_info;
t_info 	*info;
char		*ft_itoa(int n);
size_t		ft_strlen(char const *str);

#endif
