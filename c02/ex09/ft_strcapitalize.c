/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:13:59 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/16 12:18:27 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_is_alpha(char c)
{
	if ((c > 47 && c < 58) || (c > 64 && c < 91)
		|| (c > 96 && c < 123))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	in_word;
	int	i;

	i = 0;
	in_word = 1;
	while (str[i])
	{
		if (in_word == 0)
		{
			if (ft_is_alpha(str[i]) == 0)
				in_word = 1;
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
		}
		if (in_word == 1 && ft_is_alpha(str[i]) == 1)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
			in_word = 0;
		}
		i++;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "hi, how are you? 42words forty-two; fifty+and+one";
	printf("(avant) str = %s\n", str);
	char	*str2 = ft_strcapitalize(str);
	printf("(apres) str = %s\n", str);
	printf("(apres) str2 = %s\n", str2);
	return (0);
}*/
