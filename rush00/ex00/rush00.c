/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:12:20 by llepesqu          #+#    #+#             */
/*   Updated: 2025/09/14 15:34:43 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	ft_printrow(int x, char a, char b)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if ((i == 0) || (i == x - 1))
			ft_putchar(a);
		else
			ft_putchar(b);
	i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	i = 0;
	if (x < 0 || y < 0)
	{	
		write(1, "erreur : veuillez entrer des valeurs valides\n", 45);
		return ;
	}
	while (i < y)
	{
		if ((i == 0) || (i == y - 1))
			ft_printrow(x, 'o', '-');
		else
			ft_printrow(x, '|', ' ');
	i++;
	}
}
