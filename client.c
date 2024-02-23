/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:40:44 by vstineau          #+#    #+#             */
/*   Updated: 2024/02/23 15:33:39 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "LIBFT/libft.h"

void	handler(int signum, siginfo_t *info, void *context)
{
	ft_printf("signal recu par le client");

	exit(0);
}

void	send_message(int server_pid, char c)
{
	int	i;
	int	bit;

	i = 8;
	while (i-- > 0)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		pause();
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction sa;
	int	i;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	if (argc != 3)
		return (1);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr_fd("Erreur lors de l'instalation du gestionnaire de signal", 2);
		return (1);
	}
	i = 0;
	while (argv[2][i])
		send_message(ft_atoi(argv[1]), argv[2][i++]);
	return (0);
}
