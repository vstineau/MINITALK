/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:40:17 by vstineau          #+#    #+#             */
/*   Updated: 2024/02/23 17:01:09 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "LIBFT/libft.h"

typedef struct s_bit
{
	int		bit_received;
	char	char_received;
	int		bit_index;
}					t_bit;

static	t_bit	g_bit;

void	handler(int signum, siginfo_t *info, void *context)
{
	ft_printf("signal recu par le server");
	exit(0);
}

void	get_signal(int signal)
{
	char	*string;

	string = NULL;
	if (signal == SIGUSR1)
		g_bit.bit_received = 1;
	else
		g_bit.bit_received = 0;
	if (g_bit.bit_index == 8)
		g_bit.bit_index = 0;
	g_bit.char_received = (g_bit.char_received << 1) | g_bit.bit_received;
	g_bit.bit_index++;
	if (g_bit.bit_index == 8)
		string = init_string(string, g_bit.char_received);
}

int	main(void)
{
	struct sigaction sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("%d\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr_fd("Erreur lors de l'instalation du gestionnaire de signal", 2);
		return (1);
	}
	pause();
	return (0);
}
