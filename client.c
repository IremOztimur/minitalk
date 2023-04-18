/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 06:32:37 by ioztimur          #+#    #+#             */
/*   Updated: 2023/04/18 19:40:47 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_recieved(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sig == SIGUSR1)
		ft_printf("Message Received !!!");
}

void	ft_send_text(int server_pid, char *text)
{
	int	i;
	int	j;

	i = 0;
	while (text[i])
	{
		j = 0;
		while (j < 8)
		{
			if (text[i] & (1 << j))
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			j++;
			usleep(70);
		}
		i++;
	}
	j = 0;
	while (j < 8)
	{
		kill(server_pid, SIGUSR2);
		j++;
		usleep(70);
	}
}

int	main(int argc, char **av)
{
	int					server_pid;
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = ft_recieved;
	if ((sigaction(SIGUSR1, &sa, NULL) == -1))
		ft_printf("Error sigaction\n");
	if (argc != 3)
	{
		ft_printf("NOOOOOO");
		return (0);
	}
	server_pid = ft_atoi(av[1]);
	ft_send_text(server_pid, av[2]);
}
