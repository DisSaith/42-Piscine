/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:17:37 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/12 21:19:12 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	xx1;
	int	xx2;

	xx1 = 0;
	while (xx1 <= 99)
	{
		xx2 = xx1 + 1;
		while (xx2 <= 99)
		{
			ft_putchar(xx1 / 10 + '0');
			ft_putchar(xx1 % 10 + '0');
			ft_putchar(' ');
			ft_putchar(xx2 / 10 + '0');
			ft_putchar(xx2 % 10 + '0');
			if (xx1 != 98)
				write (1, ", ", 2);
			xx2++;
		}
		xx1++;
	}
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
