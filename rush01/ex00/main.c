/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-angel <nd-angel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 11:56:02 by nd-angel          #+#    #+#             */
/*   Updated: 2025/09/21 17:38:41 by nd-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	take_inputs(char argv[1], int inputs[4][4]);
void	display_grid(int towers[4][4]);
void	create_grid(int towers[4][4]);
int		ft_error_general(const char *argv, int argc);
int		solving(int towers[4][4], int loc, int inputs[4][4]);

int	main(int argc, char **argv)
{
	int	towers[4][4];
	int	inputs[4][4];

	if (ft_error_general(argv[1], argc) != 0)
		return (1);
	take_inputs(argv[1], inputs);
	create_grid(towers);
	if (solving(towers, 0, inputs) == 1)
		display_grid(towers);
	else
		write(1, "Error\n", 6);
	return (0);
}
