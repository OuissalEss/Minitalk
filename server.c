/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:46:09 by oessamdi          #+#    #+#             */
/*   Updated: 2022/04/25 08:34:29 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	print_msg(int sig)
{
	static char	c;
	static int	i;
	int			j;

	j = 7;
	if (sig == SIGUSR1)
		c = c + (1 << (j - i));
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("pid = %d\n", getpid());
	signal(SIGUSR1, print_msg);
	signal(SIGUSR2, print_msg);
	while (1)
		usleep(100);
	return (0);
}
