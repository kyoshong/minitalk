/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:57:54 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/02 17:06:08 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"


void	send_msg(char **argv)
{
	int pid;
	char *msg;

	pid = ft_atoi(argv[1]);
	msg = argv[2];
	kill(pid, SIGUSR1);
	
}

int main(int argc, char *argv[])
{
	if (argc < 3)
		return (0);
	else
	{
		send_msg(argv);
	}
	return 0;
}

