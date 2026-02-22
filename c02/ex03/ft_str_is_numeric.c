/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:13:59 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/13 10:22:30 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("val_return = %d\n", ft_str_is_numeric("Salutz"));
	printf("val_return = %d\n", ft_str_is_numeric("0123456789"));
	printf("val_return = %d\n", ft_str_is_numeric(""));
	printf("val_return = %d\n", ft_str_is_numeric("0215an,5456"));
	printf("val_return = %d\n", ft_str_is_numeric("(1!df"));
	printf("val_return = %d\n", ft_str_is_numeric("4df$"));
	return (0);
}*/
