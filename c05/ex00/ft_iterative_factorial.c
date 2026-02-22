/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:36:17 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/18 14:19:45 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_factorial(int nb)
{
	int	result;
	int	i;

	i = 1;
	result = 1;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	while (i < nb)
	{
		result *= i + 1;
		i++;
	}
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	int	nb = 7;
	printf("la factorielle de %d = %d\n", nb, ft_iterative_factorial(nb));
}*/
