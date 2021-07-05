/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:58:05 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/06 00:40:34 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_print_server(char *num, int sig)
{
	if (sig)
		write(1, "\nclient pid : ", 14);
	else
		write(1, "server pid : ", 13);
	write(1, num, ft_strlen(num));
	write(1, "\n", 1);
	free(num);
}

void	signal_handler(int signum, siginfo_t *siginfo, void *a)
{
	char		*pid;
	static int	bits;
	static int	msg;
	static int	check;
	char		tem;

	if (siginfo->si_pid != check && siginfo->si_pid > 0)
	{
		pid = ft_itoa(siginfo->si_pid);
		ft_print_server(pid, 1);
		check = siginfo->si_pid;
	}
	if (signum == SIGUSR1)
		bits = bits + (1 << (7 - msg));
	msg++;
	if (msg == 8)
	{
		tem = bits;
		write(1, &tem, 1);
		msg = 0;
		bits = 0;
	}
	(void)a;
}

void	init_sig(void)
{
	s_siga_zero.sa_sigaction = signal_handler;
	s_siga_zero.sa_flags = SA_SIGINFO;
}

int		main(void)
{
	char *pid;

	pid = ft_itoa(getpid());
	ft_print_server(pid, 0);
	init_sig();
	if (sigaction(SIGUSR1, &s_siga_zero, NULL) < 0)
	{
		write(2, "Can't catch SIGUSR1 \n", 21);
		return (1);
	}
	if (sigaction(SIGUSR2, &s_siga_zero, NULL) < 0)
	{
		write(2, "Can't catch SIGUSR2\n", 21);
		return (1);
	}
	while (1)
		pause();
	return (0);
}
