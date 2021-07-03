/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:57:54 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/04 02:07:07 by hyospark         ###   ########.fr       */
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

void		send_msg(char *msg, int pid)
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
			else if (!tem[j]&& kill(pid, SIGUSR2) == -1)
				error_exit(tem);
			j++;
			usleep(100);
		}
		free(tem);
		i++;	
	}
}

void		send_msg_length(int len, int pid)
{
	int *arr;
	int i;

	arr = binary_base(len);
	i = 0;
	while (i > 8)
	{
		if (arr[i] == 0)
		{
			kill(pid, SIGUSR1);
			printf("\nSIGUSR1\n");
		}
		else
		{
			kill(pid, SIGUSR2);
			printf("\nSIGUSR2\n");
		}
		i--;
		usleep(100);
	}
	free(arr);
}

void	start_signal(char **argv)
{
	int pid;
	char *msg;
	int mypid;

	pid = ft_atoi(argv[1]);
	msg = argv[2];
	mypid = getpid();
	printf("pid : %d", mypid);
	//send_msg_length(ft_strlen(msg), pid);
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
	return 0;
}

