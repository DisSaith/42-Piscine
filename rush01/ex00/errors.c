/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nd-angel <nd-angel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:58:29 by nd-angel          #+#    #+#             */
/*   Updated: 2025/09/21 17:40:46 by nd-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	ft_error_number_arg(int argc)
{
	if (argc != 2)
		return (ft_print_error());
	return (0);
}

int	ft_error_general(const char *argv, int argc)
{
	int	i;

	if (ft_error_number_arg(argc))
		return (1);
	i = 0;
	while (i < 31)
	{
		if ((i % 2) == 0)
		{
			if (argv[i] < '1' || argv[i] > '4')
				return (ft_print_error());
		}
		else
		{
			if (argv[i] != ' ')
				return (ft_print_error());
		}
		i++;
	}
	if (argv[31] != '\0')
		return (ft_print_error());
	return (0);
}
