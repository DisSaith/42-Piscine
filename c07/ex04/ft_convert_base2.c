/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:01:06 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/22 18:29:26 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_verif_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (1);
		if (base[i] <= 32 || base[i] == 127)
			return (1);
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_fill_tab(int size, char *tab, int is_negative)
{
	char	*result;
	int		i;
	int		j;

	i = size - 1;
	j = 0;
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	if (is_negative)
		result[j++] = '-';
	while (i >= 0)
		result[j++] = tab[i--];
	result[j] = '\0';
	return (result);
}
