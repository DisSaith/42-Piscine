/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:42:37 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/12 12:00:06 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}
/*
int	main(void)
{
	int	a;
	int	b;

	a = 12;
	b = 42;
	printf("avant swap : a = %d ; b = %d\n", a, b);
	ft_swap(&a, &b);
	printf("apres swap : a = %d ; b = %d\n", a, b);
	return (0);
}*/
