/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:09:44 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/14 15:33:12 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	display_rectangle(char left, char middle, char right, int colomn)
{
	int	i;

	i = 1;
	while (i <= colomn)
	{
		if (i == 1)
			ft_putchar(left);
		if (i < colomn && i > 1)
			ft_putchar(middle);
		if (i == colomn && i != 1)
			ft_putchar(right);
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	i = 1;
	if (x < 0 || y < 0)
	{	
		write(1, "erreur : veuillez entrer des valeurs valides\n", 45);
		return ;
	}
	while (i <= y)
	{
		if (i == 1)
			display_rectangle('A', 'B', 'C', x);
		if (i < y && i > 1)
			display_rectangle('B', ' ', 'B', x);
		if (i == y && i != 1)
			display_rectangle('A', 'B', 'C', x);
		i++;
	}
}
