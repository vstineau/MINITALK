/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:50:08 by vstineau          #+#    #+#             */
/*   Updated: 2023/11/14 13:29:33 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
			i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
			nb = nb * 10 + (nptr[i] - 48);
			i++;
	}
	return (nb * sign);
}
/*
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_atoi("123"));
	printf("%d\n", ft_atoi("-123"));
	printf("%d\n", ft_atoi("  -123"));
	printf("%d\n", ft_atoi("  +-123"));
	printf("%d\n", ft_atoi("  + 123"));
	printf("%d\n", ft_atoi(" +12 3"));
	printf("%d\n", ft_atoi(" -12l3"));
}*/
