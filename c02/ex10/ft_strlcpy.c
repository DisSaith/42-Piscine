/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:02:32 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/16 14:10:35 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (size < 1)
		return (len);
	while (i < size - 1 && src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}
/*
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	str1[] = "";
	char	str2[] = "Ca ?";
	size_t	size;
	printf("(avant) src = %s\n", str1);
	printf("(avant) dest = %s\n", str2);
	size = ft_strlcpy(str2, str1, sizeof(str2));
	printf("size = %zu\n", size);
	printf("(apres) dest = %s\n", str2);
	//ajouter flag -lbsd

}*/
