/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:58:05 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/04 02:27:18 by hyospark         ###   ########.fr       */
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
}

void		signal_handler(int signum, siginfo_t *siginfo, void *a)
{
	//char *pid;
	static int	bits = 0;
	static int	msg = 0;
	char tem;

	printf("siginfo->si_pid : %d\n",siginfo->si_pid);
	// if (siginfo->si_pid != info->check)
	// {
	// 	pid = ft_itoa(siginfo->si_pid);
	// 	info->check = siginfo->si_pid;
	// 	ft_print_server(pid, 1);
	// }
	if (signum == SIGUSR1)
		bits = bits + (1 << (7 - msg));
	msg += 1;
	if (msg == 8)
	{
		tem = bits;
		write(1, &tem, 1);
		msg = 0;
		bits = 0;
	}
	(void)a;
}

void	init_sig()
{
	s_siga_zero.sa_sigaction = signal_handler;
	s_siga_zero.sa_flags = SA_SIGINFO;
}

int		main()
{
	char *pid;

	pid = ft_itoa(getpid());
	ft_print_server(pid, 0);
	init_sig();
	if (sigaction(SIGUSR1, &s_siga_zero, NULL) < 0)
	{
		printf("Can't catch SIGUSR1 \n");
		return (1);
	}
	if (sigaction(SIGUSR2, &s_siga_zero, NULL) < 0)
	{
		printf("Can't catch SIGUSR1 \n");
		return (1);
	}
	while (1)
		pause();
	return 0;
}
