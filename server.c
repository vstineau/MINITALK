/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:40:17 by vstineau          #+#    #+#             */
/*   Updated: 2024/02/28 11:43:14 by vstineau         ###   ########.fr       */
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
	char	char_get;
	char	*str;
	int		bit_index;
	int		str_len;
}					t_bit;

static t_bit	g_bit;

void	get_bit(int signal)
{
	if (signal == SIGUSR1)
		g_bit.bit_received = 1;
	else
		g_bit.bit_received = 0;
	g_bit.char_get = g_bit.char_get | (g_bit.bit_received << g_bit.bit_index);
	g_bit.bit_index++;
	if (g_bit.bit_index == 8)
	{
		g_bit.bit_index = 0;
		g_bit.str = ft_realloc(g_bit.str, g_bit.str_len, (g_bit.str_len + 1));
		g_bit.str[g_bit.str_len] = g_bit.char_get;
		g_bit.str_len++;
		if (g_bit.char_get == 0)
		{
			write(1, g_bit.str, g_bit.str_len);
			write(1, "\n", 1);
			free(g_bit.str);
			g_bit.str = NULL;
			g_bit.str_len = 0;
		}
		g_bit.char_get = 0;
	}
}

void	handler(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	(void)info;
	(void)context;
	get_bit(signum);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("%d\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);
	while (1)
		pause();
	return (0);
}
