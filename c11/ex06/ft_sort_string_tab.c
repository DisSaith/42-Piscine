/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:41:50 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/25 13:16:57 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	char	*switchi;
	int		i;
	int		j;

	i = 0;
	while (tab[i] != NULL)
	{
		j = i + 1;
		while (tab[j] != NULL)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				switchi = tab[i];
				tab[i] = tab[j];
				tab[j] = switchi;
			}
			j++;
		}
		i++;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	char	*tab[] = {"luke", "R2D2", "C3PO", "42", "ANTOINE", "1darkvador", NULL};
	for (int i = 0 ; i < 6 ; i++)
		printf("(avant) tab[%d] = %s\n", i, tab[i]);
	ft_sort_string_tab(tab);
	for (int i = 0 ; i < 6 ; i++)
		printf("(apres) tab[%d] = %s\n", i, tab[i]);
	return (0);
}*/
