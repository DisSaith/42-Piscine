/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:16:58 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/24 11:24:08 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*
int	is_negative(int a)
{
	if (a < 0)
		return (1);
	return (0);
}
*/

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*nw_tab;

	i = 0;
	nw_tab = malloc(sizeof(int) * length);
	while (i < length)
	{
		nw_tab[i] = (*f)(tab[i]);
		i++;
	}
	return (nw_tab);
}

/*
#include <stdio.h>

int	main(void)
{
	int tab[] = {42, 10, -2, -10, 100, 32, 20, 4, -20};
	int *nw_tab = ft_map(tab, 9, &is_negative);
	for (int i = 0 ; i < 9 ; i++)
		printf("nw_tab[%d] = %d\n", i, nw_tab[i]);
	free(nw_tab);
	return (0);
}*/
