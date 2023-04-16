/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 04:33:23 by ioztimur          #+#    #+#             */
/*   Updated: 2023/04/16 06:21:27 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	handler(int	sig, siginfo_t* info, void* context)
{
	(void)context;
	(void)info;
	static int	output;
	static int	pid_client;
	static int	i;

	if (sig == SIGUSR1 && i < 32)
		pid_client = pid_client | (1 << i);
	else if (sig == SIGUSR1 && i < 40)
		output = output | (1 << i);
	i++;
	if (i == 40)
	{
		if (output != 0)
		{
			write(1, &output, 1);
			i = 32;
		}
		else
		{
			kill(pid_client, SIGUSR1);
			pid_client = 0;
			i = 0;
		}
		output = 0;
	}
}

int	main()
{
	struct sigaction	sa;

	ft_printf("Server started!\nPID: %d", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = handler;
	if ((sigaction(SIGUSR1, &sa, NULL) == -1))
		ft_printf("Error sigaction\n");
	if ((sigaction(SIGUSR1, &sa, NULL) == -1))
		ft_printf("Error sigaction\n");
	while (1)
		pause();
	return (0);
}
