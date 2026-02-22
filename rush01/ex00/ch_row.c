/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_row.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-angel <nd-angel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:41:46 by nd-angel          #+#    #+#             */
/*   Updated: 2025/09/21 16:18:56 by nd-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ch_in_row(int towers[4][4], int row, int val)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (towers[row][col] == val)
			return (1);
		col++;
	}
	return (0);
}

int	count_vis_left(int towers[4][4], int row)
{
	int	visibility;
	int	four;
	int	col;

	visibility = 0;
	four = 0;
	col = 0;
	while (col < 4)
	{
		if (towers[row][col] > four)
		{
			four = towers[row][col];
			visibility++;
		}
		col++;
	}
	return (visibility);
}

int	count_vis_right(int towers[4][4], int row)
{
	int	visibility;
	int	four;
	int	col;

	visibility = 0;
	four = 0;
	col = 3;
	while (col >= 0)
	{
		if (towers[row][col] > four)
		{
			four = towers[row][col];
			visibility++;
		}
		col--;
	}
	return (visibility);
}

int	ch_vis_row(int towers[4][4], int row, int inputs[4][4])
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (towers[row][col] == 0)
			return (1);
		col++;
	}
	if (count_vis_left(towers, row) != inputs[2][row]
		|| count_vis_right(towers, row) != inputs[3][row])
		return (0);
	return (1);
}
