/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:50:24 by acohaut           #+#    #+#             */
/*   Updated: 2025/10/01 18:18:36 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	zero_intmin(int nb)
{
	if (nb == 0)
	{
		write(1, "0\n", 2);
		return ;
	}
	if (nb == -2147483648)
	{
		write(1, "-2147483648\n", 12);
		return ;
	}
}

void	ft_putnbr(int nb)
{
	char	tab[11];
	int		i;

	i = 0;
	if (nb == 0 || nb == -2147483648)
	{
		zero_intmin(nb);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	while (nb > 0)
	{
		tab[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	while (i-- > 0)
		ft_putchar(tab[i]);
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	int	(*f[5])(int, int);
	int	a;
	int	b;

	if (argc != 4)
		return (errors(argc, "", 0, 0));
	init_tab(f);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if (errors(argc, argv[2], a, b))
		return (1);
	if (argv[2][0] == '+')
		ft_putnbr((*f[0])(a, b));
	else if (argv[2][0] == '-')
		ft_putnbr((*f[1])(a, b));
	else if (argv[2][0] == '/')
		ft_putnbr((*f[2])(a, b));
	else if (argv[2][0] == '*')
		ft_putnbr((*f[3])(a, b));
	else if (argv[2][0] == '%')
		ft_putnbr((*f[4])(a, b));
	else
		write(1, "0\n", 2);
	return (0);
}
