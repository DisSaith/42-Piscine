/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:54:00 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/16 16:58:04 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	char	*find;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			find = &str[i];
			while (str[i + j] == to_find[j] && to_find[j])
				j++;
			if (to_find[j] == '\0')
				return (find);
		}
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	str1[] = "Bomjour, tu rarararasputine, ca va ?";
	char	str2[] = "rasputine";
	printf("botte de foin = %s\n", str1);
	printf("aiguille = %s\n", str2);
	char 	*trouve = ft_strstr(str1, str2);
	printf("trouve = %s\n", trouve);
}*/
