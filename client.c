/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:40:44 by vstineau          #+#    #+#             */
/*   Updated: 2024/02/22 17:19:48 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	handler(int signum, siginfo_t *info, void *context)
{
	ft_printf("signal recu par le client");
	exit(0);
}

int	main(int argc, char *argv[])
{
	struct sigaction sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	if (argc != 3)
		return (1);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_putstr_fd("Erreur lors de l'instalation du gestionnaire de signal", 2);
		return (1);
	}
	kill(ft_atoi(argv[1]), SIGUSR1);
	return (0);
}
