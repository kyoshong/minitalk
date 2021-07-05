/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:57:54 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/06 00:24:28 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		*binary_base(int num)
{
	int *arr;
	int i;

	if (!(arr = (int *)malloc(sizeof(int) * 8)))
		return (0);
	i = 0;
	while (i <= 7)
	{
		arr[i] = 0;
		i++;
	}
	i = 7;
	while (num > 0)
	{
		if (num % 2)
			arr[i] = 1;
		else
			arr[i] = 0;
		num = num / 2;
		i--;
	}
	return (arr);
}

void	send_msg(char *msg, int pid)
{
	int i;
	int j;
	int *tem;

	i = 0;
	while (msg[i])
	{
		tem = binary_base(msg[i]);
		j = 0;
		while (j < 8)
		{
			if (tem[j] && kill(pid, SIGUSR1) == -1)
				error_exit(tem);
			else if ((!tem[j]) && kill(pid, SIGUSR2) == -1)
				error_exit(tem);
			j++;
			usleep(100);
		}
		free(tem);
		i++;
	}
}

void	start_signal(char **argv)
{
	int		pid;
	char	*msg;
	char	*mypid;

	pid = ft_atoi(argv[1]);
	msg = argv[2];
	mypid = ft_itoa(getpid());
	write(1, "client pid : ", 13);
	write(1, mypid, ft_strlen(mypid));
	write(1, "\n", 1);
	free(mypid);
	send_msg(msg, pid);
}

int		main(int argc, char *argv[])
{
	if (argc < 3)
		return (0);
	else
	{
		start_signal(argv);
	}
	return (0);
}
