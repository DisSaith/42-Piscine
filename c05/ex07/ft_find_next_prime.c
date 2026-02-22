/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:48:48 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/17 11:15:21 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (2);
	if (ft_is_prime(nb))
		return (nb);
	while (!(ft_is_prime(nb)))
		nb++;
	return (nb);
}
/*
#include <stdio.h>

int	main(void)
{
	int	nb = 84;
	printf("%d est nb premier ? >> %d\n", nb, ft_is_prime(nb));
	printf("next prime >> %d\n", ft_find_next_prime(nb));
	return (0);
}*/
