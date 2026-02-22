/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:41:50 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/29 13:50:31 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
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
*/

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	*switchi;
	int		i;
	int		sorted;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (tab[i] && tab[i + 1])
		{
			if ((*cmp)(tab[i], tab[i + 1]) > 0)
			{
				switchi = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = switchi;
				sorted = 0;
			}
			i++;
		}
	}
}

/*
#include <stdio.h>

int	main(void)
{
	char	*tab[] = {"luke", "R2D2", "C3PO", "42", "ANTOINE", "1darkvador", NULL};
	for (int i = 0 ; i < 6 ; i++)
		printf("(avant) tab[%d] = %s\n", i, tab[i]);
	ft_advanced_sort_string_tab(tab, &ft_strcmp);
	for (int i = 0 ; i < 6 ; i++)
		printf("(apres) tab[%d] = %s\n", i, tab[i]);
	return (0);
}*/
