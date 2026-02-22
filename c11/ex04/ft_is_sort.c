/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:01:15 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/29 09:35:56 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
int	ft_intcmp(int a, int b)
{
	return (a - b);
}
*/

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	crois;
	int	decrois;

	i = 0;
	crois = 1;
	decrois = 1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			crois = 0;
		if (f(tab[i], tab[i + 1]) < 0)
			decrois = 0;
		i++;
	}
	return (crois || decrois);
}

/*
#include <stdio.h>

int	main(void)
{
	int tab[] = {1, 2, 9, 8, 10, 13, 15};
	printf("retour = %d\n", ft_is_sort(tab, 7, &ft_intcmp));
}*/
