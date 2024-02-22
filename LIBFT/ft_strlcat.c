/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:30:58 by vstineau          #+#    #+#             */
/*   Updated: 2023/11/16 15:50:21 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ldst;
	size_t	lsrc;

	i = 0;
	if (!dst && !src)
		return (0);
	if (size == 0 && (!dst || !src))
		return (0);
	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (size == 0)
		return (lsrc);
	if (size < ldst)
		return (size + lsrc);
	while (src[i] && (size - 1 > ldst + i))
	{
		dst[ldst + i] = src[i];
		i++;
	}
	if (ldst < size)
		dst[ldst + i] = '\0';
	dst[ldst + i] = '\0';
	return (ldst + lsrc);
}
/*
#include <stdio.h>
#include <bsd/string.h>
#include <string.h>
int main()
{
	char dest[30]; ft_memset(dest, 0,30);
	char dest1[30]; ft_memset(dest1, 0,30);
	dest[0] = 'B';
	dest1[0] = 'B';
	printf("%zu\n", ft_strlcat(dest, "123", 0));
	printf("%s\n", dest);
	printf("%zu\n", strlcat(dest1, "123", 0));
	printf("%s\n", dest1);
}*/
