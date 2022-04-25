/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:58:24 by oessamdi          #+#    #+#             */
/*   Updated: 2022/04/25 08:34:11 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	msg_error(char *msg)
{
	ft_printf("%s", msg);
	return (0);
}

void	send_char(int pid, char x)
{
	int	i;

	i = 128;
	while (i > 0)
	{
		if (x >= i)
		{
			kill(pid, SIGUSR1);
			x = x - i;
		}
		else
			kill(pid, SIGUSR2);
		i = i / 2;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
		return (msg_error("wrong number of arguments\n"));
	i = 0;
	pid = ft_atoi(av[1], &i);
	if (i != 0 || pid <= 0)
		return (msg_error("wrong server PID\n"));
	while (av[2][i])
	{
		send_char(pid, av[2][i]);
		i++;
	}
	send_char(pid, '\n');
	return (0);
}
