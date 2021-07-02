/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:58:05 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/02 17:16:45 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_print(char *arg)
{
	write(1, arg, ft_strlen(arg));
	write(1, "\n", 1);
}

void	signal_handler(int signum)
{
	printf("signum : %d\n", signum);
}

int		main()
{
	char *pid;
	pid = ft_itoa(getpid());

	write(1, "server pid : ", 13);
	write(1, pid, ft_strlen(pid));
	while (1)
	{
		pause();
	}
	if ((SIG_ERR == signal(SIGUSR1, signal_handler)))
		return (1);
	write(1, "client pid : ", 13);
	return 0;
}
