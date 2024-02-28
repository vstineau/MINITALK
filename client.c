/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <vstineau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:40:44 by vstineau          #+#    #+#             */
/*   Updated: 2024/02/28 11:44:05 by vstineau         ###   ########.fr       */
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
	int		bit_send;
	char	*str;
	int		bit_index;
	pid_t	pid;
}					t_bit;

static t_bit	g_send;

void	send_bit(int server_pid, char c)
{
	int	bit;

	bit = (c >> (g_send.bit_index % 8)) & 1;
	if (bit == 1)
		kill(server_pid, SIGUSR1);
	else
		kill(server_pid, SIGUSR2);
}

void	send_string(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	(void)info;
	(void)context;
	if (g_send.bit_index <= (int)(ft_strlen(g_send.str) + 1) *8)
	{
		send_bit(g_send.pid, g_send.str[g_send.bit_index / 8]);
		g_send.bit_index++;
	}
	else
		return ;
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	int					i;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = send_string;
	sa.sa_flags = SA_SIGINFO;
	if (argc != 3)
		return (1);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	i = 0;
	g_send.pid = (pid_t)ft_atoi(argv[1]);
	g_send.str = ft_strdup(argv[2]);
	send_string(0, NULL, NULL);
	while (g_send.bit_index < (int)(ft_strlen(g_send.str) + 1) *8)
		pause();
	free(g_send.str);
	return (0);
}
