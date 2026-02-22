/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:13:59 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/13 10:23:56 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (str[i] < 97 || str[i] > 122)
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("val_return = %d\n", ft_str_is_lowercase("abcdefghijklmnopwz"));
	printf("val_return = %d\n", ft_str_is_lowercase("0123456789"));
	printf("val_return = %d\n", ft_str_is_lowercase(""));
	printf("val_return = %d\n", ft_str_is_lowercase("ANKDDdd,5456"));
	printf("val_return = %d\n", ft_str_is_lowercase("(1!df"));
	printf("val_return = %d\n", ft_str_is_lowercase("andhdjA"));
	return (0);
}*/
