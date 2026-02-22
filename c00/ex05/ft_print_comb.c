/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:09:30 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/10 14:14:23 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	while (a <= 7)
	{
		b = a;
		while (b++ <= 8)
		{
			c = b;
			while (c++ < 9)
			{
				if (a != b && b != c && c != a)
				{
					ft_putchar(a + '0');
					ft_putchar(b + '0');
					ft_putchar(c + '0');
					if (a != 7)
						write(1, ", ", 2);
				}
			}
		}
	a++;
	}
}
/*
int	main(void)
{
	ft_print_comb();
	return (0);
}*/
