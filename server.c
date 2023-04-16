/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 04:33:23 by ioztimur          #+#    #+#             */
/*   Updated: 2023/04/16 04:53:45 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	handler(int	sig)
{
	int

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
