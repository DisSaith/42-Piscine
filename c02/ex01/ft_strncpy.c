/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:39:40 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/15 12:01:12 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int     main(void)
{
        char    src[] =  "Salut toi";
        char    dest[] = "Bonjour toi";

        printf("src = %s\n", src);
        printf("(avant) dest = %s\n", dest);
        ft_strncpy(dest, src, 5);
        printf("(apres) dest = %s\n", dest);
        return (0);
}*/
