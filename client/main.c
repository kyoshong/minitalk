/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:57:54 by hyospark          #+#    #+#             */
/*   Updated: 2021/07/02 23:13:51 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		*binary_base(int num)
{
	int *arr;
	int i;

	if (!(arr = (int *)malloc(sizeof(int) * 8)))
		return (0);
	i = 7;
	while (i >= 0)
	{
		if (num % 2)
		{
			num = num / 2;
			arr[i] = 1;
		}
		else
			arr[i] = 0;
		i--;
	}
	return (arr);
}

void	send_msg_length()
{
	int pid;
	binary_base(pid);
}

void	start_signal(char **argv)
{
	int pid;
	char *msg;
	int mypid;


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
		start_signal(argv);
	}
	return 0;
}

