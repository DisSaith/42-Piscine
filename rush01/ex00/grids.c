/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grids.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-angel <nd-angel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:54:39 by nd-angel          #+#    #+#             */
/*   Updated: 2025/09/21 15:57:30 by nd-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	create_grid(int towers[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			towers[row][col] = 0;
			col++;
		}
		row++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putint(int a)
{
	ft_putchar(a + '0');
}

void	display_grid(int towers[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			ft_putint(towers[row][col]);
			if (col < 3)
				ft_putchar(' ');
			col++;
			if (col == 4)
				ft_putchar('\n');
		}
		row++;
	}
}

void	take_inputs(char argv[1], int inputs[4][4])
{
	int	row;
	int	col;
	int	i;

	row = 0;
	i = 0;
	while (row < 4 && argv[i])
	{
		col = 0;
		while (col < 4)
		{
			if (argv[i] >= '0' && argv[i] <= '9')
			{
				inputs[row][col] = argv[i] - 48;
				col++;
			}
			i++;
		}
		row++;
	}
}
