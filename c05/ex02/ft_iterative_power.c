/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:54:12 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/18 14:32:40 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_power(int nb, int power)
{
	int	result;
	int	i;

	i = 1;
	result = nb;
	if (power < 0)
		return (0);
	if (power == 0 || nb == 0)
		return (1);
	while (i++ < power)
		result *= nb;
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	int	nb = 1;
	int	power = 1;
	printf("%d puissance %d = %d\n", nb, power, 
		ft_iterative_power(nb, power));
}*/
