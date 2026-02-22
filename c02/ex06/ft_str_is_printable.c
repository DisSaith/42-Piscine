/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:13:59 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/16 12:03:04 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("val_return = %d\n", ft_str_is_printable("abcdefghijklmnopwz"));
	printf("val_return = %d\n", ft_str_is_printable("0123456789"));
	printf("val_return = %d\n", ft_str_is_printable(""));
	printf("val_return = %d\n", ft_str_is_printable("\b"));
	printf("val_return = %d\n", ft_str_is_printable("(1!df"));
	printf("val_return = %d\n", ft_str_is_printable("andhdjA"));
	return (0);
}*/
