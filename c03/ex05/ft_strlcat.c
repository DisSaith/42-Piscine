/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:26:08 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/16 11:49:29 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len_d;
	unsigned int	len_d_start;
	unsigned int	len_s_start;

	len_d_start = ft_strlen(dest);
	len_s_start = ft_strlen(src);
	i = 0;
	len_d = ft_strlen(dest);
	if (size == 0)
		return (len_s_start);
	if (size < len_d)
		return (len_s_start + size);
	while (src[i] && size - 1 > len_d)
	{
		dest[len_d] = src[i];
		i++;
		len_d++;
	}
	dest[len_d] = '\0';
	return (len_d_start + len_s_start);
}
/*
#include <bsd/string.h>
#include <stdio.h>

int		main(void)
{
	char	str1[] = "Ca va bg ?";
	char	str2[] = "Salut. ";
	printf("src = %s\n", str1);
	printf("(avant) dest = %s\n", str2);
	unsigned size = strlcat(str2, str1, 0);
	printf("(apres) dest = %s | size = %d\n", str2, size);
	//ajouter flag -lbsd pour tester strlcat
}*/
