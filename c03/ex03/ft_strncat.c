/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:26:08 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/15 17:20:01 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	len_d;

	i = 0;
	len_d = ft_strlen(dest);
	while (src[i] && i < nb)
	{
		dest[len_d] = src[i];
		i++;
		len_d++;
	}
	dest[len_d] = '\0';
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	str1[] = "Ca va bg ?";
	char	str2[] = "Salut. ";
	printf("(avant) dest = %s\n", str2);
	ft_strncat(str2, str1, 2);
	printf("(apres) dest = %s\n", str2);
}*/
