/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 16:04:41 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/14 16:18:10 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str = "Bonjour cher.e testeur.teuse";
	printf("retour strlen = %d", ft_strlen(str));
	ft_putstr(str);
	return (0);
}*/
