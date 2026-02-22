/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:28:25 by acohaut           #+#    #+#             */
/*   Updated: 2025/10/01 17:58:36 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	init_tab(int (*f[5])(int, int))
{
	f[0] = &add;
	f[1] = &sous;
	f[2] = &divi;
	f[3] = &mul;
	f[4] = &mod;
}

int	errors(int argc, char *str, int a, int b)
{
	(void)a;
	if (argc != 4)
	{
		write(1, "0\n", 2);
		return (1);
	}
	if (str[1] != '\0')
	{
		write(1, "0\n", 2);
		return (1);
	}
	if (str[0] == '/' && b == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (1);
	}
	if (str[0] == '%' && b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (1);
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	atoi;
	int	sign;
	int	i;

	sign = 1;
	atoi = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		atoi *= 10;
		atoi += str[i] - 48;
		i++;
	}
	return (atoi * sign);
}
