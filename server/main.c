/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:58:05 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/02 23:15:57 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_print_server()
{
	char *pid;
	
	pid = ft_itoa(getpid());
	write(1, "server pid : ", 13);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
}

void		signal_zero_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		write(1, "sow", 3);
	}
}

void		signal_one_handler(int signum)
{
	if (signum == SIGUSR2)
	{
		write(1, "SIGUSR2", 7);
	}
}

void	init_siga()
{
	s_siga.__sigaction_u.__sa_handler = &signal_one_handler;
	s_siga.sa_mask;
	s_siga.sa_flags = SA_SIGINFO;
}

int		main()
{
	ft_print_server();
	init_siga();
	
	if (sigaction(SIGUSR1, &s_siga, NULL) < 0)
	{
		printf("Can't catch SIGUSR1 \n");
		return (1);
	}
	if (sigaction(SIGUSR2, &s_siga, NULL) < 0)
	{
		printf("Can't catch SIGUSR1 \n");
		return (1);
	}
	while (1)
		pause();
	
	return 0;
}
