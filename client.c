/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:40:44 by vstineau          #+#    #+#             */
/*   Updated: 2024/02/22 15:54:44 by vstineau         ###   ########.fr       */
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
	if (argc != 3)
		return (1);
}
