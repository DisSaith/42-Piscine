/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:26:08 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/13 16:43:26 by acohaut          ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len_d;

	i = 0;
	len_d = ft_strlen(dest);
	while (src[i])
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
	ft_strcat(str2, str1);
	printf("(apres) dest = %s\n", str2);
}*/
