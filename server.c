/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:40:17 by vstineau          #+#    #+#             */
/*   Updated: 2024/02/22 16:16:35 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "LIBFT/ft_printf.h"
#include "LIBFT/libft.h"

void	handler(int signum, siginfo_t *info, void *context)
{
	ft_printf("signal recu par le server");
	exit(0);
}

int	main(void)
{
	struct sigaction sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_putstr_fd("Erreur lors de l'instalation du gestionnaire de signal", 2);
		return (1);
	}
	pause();
	return (0);
}
