/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:41:02 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/13 10:16:48 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122)
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("val_return = %d\n", ft_str_is_alpha("Salutz"));
	printf("val_return = %d\n", ft_str_is_alpha(""));
	printf("val_return = %d\n", ft_str_is_alpha("Sa21lut"));
	printf("val_return = %d\n", ft_str_is_alpha(")orlld"));
	printf("val_return = %d\n", ft_str_is_alpha("ANDKDZ"));
	printf("val_return = %d\n", ft_str_is_alpha("~+="));
	return (0);
}*/
