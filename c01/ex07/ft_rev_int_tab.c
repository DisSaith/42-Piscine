/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:40:02 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/14 11:17:21 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_rev_int_tab(int *tab, int size)
{
	int	switchi;
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		switchi = tab[i];
		tab[i] = tab[j];
		tab[j] = switchi;
		i++;
		j--;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	int	tab[9] = {1, 4, 6, 9, 12, 14, 15, 21, 42};
	for (int i = 0 ; i < 9 ; i++)
		printf("avant  : tab[%d] = %d\n", i, tab[i]);
	ft_rev_int_tab(tab, 9);
	printf("\n");
	for (int i = 0 ; i < 9 ; i++)
		printf("apres  : tab[%d] = %d\n", i, tab[i]);
	return (0);
}*/
