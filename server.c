/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 04:33:23 by ioztimur          #+#    #+#             */
/*   Updated: 2023/04/18 16:23:07 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_output(int output)
{
	write(1, &output, 1);
	return (0);
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static int	output;
	static int	pid_client;
	static int	i;

	if (pid_client == 0)
		pid_client = info->si_pid;
	(void)context;
	if (sig == SIGUSR1 && i < 8)
		output = output | (1 << i);
	i++;
	if (i == 8)
	{
		if (output != 0)
			i = ft_output(output);
		else
		{
			kill(pid_client, SIGUSR1);
			pid_client = 0;
			i = 0;
		}
		output = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server started!\nPID: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = handler;
	if ((sigaction(SIGUSR1, &sa, NULL) == -1))
		ft_printf("Error sigaction\n");
	if ((sigaction(SIGUSR2, &sa, NULL) == -1))
		ft_printf("Error sigaction\n");
	while (1)
		pause();
	return (0);
}
