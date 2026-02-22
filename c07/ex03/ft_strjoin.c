/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 10:09:30 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/28 12:36:05 by acohaut          ###   ########.fr       */
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

int	ft_strslen(char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	count;
	int	valid_strings;

	i = 0;
	count = 0;
	valid_strings = 0;
	while (i < size && strs[i] != NULL)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			count++;
			j++;
		}
		valid_strings++;
		i++;
	}
	if (valid_strings > 0)
		return (count + ft_strlen(sep) * (valid_strings - 1));
	return (0);
}

void	ft_fillstr(char *tab, char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	h;
	int	f;

	i = 0;
	h = 0;
	while (i < size && strs[i] != NULL)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			tab[h] = strs[i][j];
			h++;
			j++;
		}
		f = 0;
		if (i + 1 < size && strs[i + 1] != NULL)
			while (sep[f])
				tab[h++] = sep[f++];
		i++;
	}
	tab[h] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;

	if (size == 0)
	{
		tab = malloc(1);
		if (tab)
			tab[0] = '\0';
		return (tab);
	}
	if (!sep)
		sep = "";
	tab = malloc(sizeof(char) * (ft_strslen(strs, sep, size) + 1));
	if (!tab)
		return (NULL);
	ft_fillstr(tab, strs, sep, size);
	return (tab);
}

#include <stdio.h>

int	main(void)
{
	char	*strs[] = {"Salut", "", "Ciao", "", "Yolo", NULL};
	char	*sep = ",    ";
	char	*result = ft_strjoin(5, strs, sep);
	printf("result = %s\n", result);
	free (result);
}
