/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:04:11 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/12 20:45:37 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	src[] =  "Salut";
	char	dest[] = "Bonjour toi";

	printf("src = %s\n", src);
	printf("(avant) dest = %s\n", dest);
	ft_strcpy(dest, src);
	printf("(apres) dest = %s\n", dest);
	return (0);
}*/
