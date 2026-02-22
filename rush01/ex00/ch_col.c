/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_col.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-angel <nd-angel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:50:27 by nd-angel          #+#    #+#             */
/*   Updated: 2025/09/21 16:17:33 by nd-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ch_in_col(int towers[4][4], int col, int val)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (towers[row][col] == val)
			return (1);
		row++;
	}
	return (0);
}

int	count_vis_top(int towers[4][4], int col)
{
	int	visibility;
	int	four;
	int	row;

	visibility = 0;
	four = 0;
	row = 0;
	while (row < 4)
	{
		if (towers[row][col] > four)
		{
			four = towers[row][col];
			visibility++;
		}
		row++;
	}
	return (visibility);
}

int	count_vis_bot(int towers[4][4], int col)
{
	int	visibility;
	int	four;
	int	row;

	visibility = 0;
	four = 0;
	row = 3;
	while (row >= 0)
	{
		if (towers[row][col] > four)
		{
			four = towers[row][col];
			visibility++;
		}
		row--;
	}
	return (visibility);
}

int	ch_vis_col(int towers[4][4], int col, int inputs[4][4])
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (towers[row][col] == 0)
			return (1);
		row++;
	}
	if (count_vis_top(towers, col) != inputs[0][col]
			|| count_vis_bot(towers, col) != inputs[1][col])
		return (0);
	return (1);
}
