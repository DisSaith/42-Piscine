/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:48:35 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/13 16:10:20 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("val_mine = %d\n", ft_strcmp("SLT", "SLT"));
	printf("val_strcmp = %d\n", strcmp("SLT", "SLT"));
	printf("val_mine = %d\n", ft_strcmp("test", "TEST"));
	printf("val_strcmp = %d\n", strcmp("test", "TEST"));
	printf("val_mine = %d\n", ft_strcmp("123", "321"));
	printf("val_strcmp = %d\n", strcmp("123", "321"));
	return (0);
}*/
