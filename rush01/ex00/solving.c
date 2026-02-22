/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 09:47:40 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/21 16:59:14 by nd-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	solving(int towers[4][4], int loc, int inputs[4][4]);
int	ch_vis_row(int towers[4][4], int row, int inputs[4][4]);
int	ch_in_row(int towers[4][4], int row, int val);
int	ch_in_col(int towers[4][4], int col, int val);
int	ch_vis_col(int towers[4][4], int col, int inputs[4][4]);

int	try_val(int towers[4][4], int val, int loc, int inputs[4][4])
{
	int	col;
	int	row;

	row = loc / 4;
	col = loc % 4;
	if (!ch_in_row(towers, row, val) && !ch_in_col(towers, col, val))
	{
		towers[row][col] = val;
		if (ch_vis_row(towers, row, inputs) == 0
			|| ch_vis_col(towers, col, inputs) == 0)
		{
			towers[row][col] = 0;
			return (0);
		}
		if (solving(towers, loc + 1, inputs))
			return (1);
		towers[row][col] = 0;
	}
	return (0);
}

int	solving(int towers[4][4], int loc, int inputs[4][4])
{
	int	val;

	if (loc == 4 * 4)
		return (1);
	val = 1;
	while (val <= 4)
	{
		if (try_val(towers, val, loc, inputs))
			return (1);
		val++;
	}
	return (0);
}
