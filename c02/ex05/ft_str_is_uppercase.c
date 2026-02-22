/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:13:59 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/13 10:25:19 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (str[i] < 65 || str[i] > 90)
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("val_return = %d\n", ft_str_is_uppercase("ABCDEFXYZ"));
	printf("val_return = %d\n", ft_str_is_uppercase("0123456789"));
	printf("val_return = %d\n", ft_str_is_uppercase(""));
	printf("val_return = %d\n", ft_str_is_uppercase("ANKDDdd,5456"));
	printf("val_return = %d\n", ft_str_is_uppercase("(1!df"));
	printf("val_return = %d\n", ft_str_is_uppercase("andhdjA"));
	return (0);
}*/
