/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:03:05 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/18 14:28:24 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_recursive_factorial(int nb)
{	
	if (nb == 1 || nb == 0)
		return (1);
	if (nb > 1)
		return (nb * ft_recursive_factorial(nb - 1));
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	int	nb = -1;
	printf("la factorielle de %d = %d\n", nb, ft_recursive_factorial(nb));
	return (0);
}*/
