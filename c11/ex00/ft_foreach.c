/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:38:13 by acohaut           #+#    #+#             */
/*   Updated: 2025/09/24 10:16:32 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	tab[11];
	int		i;

	i = 0;
	if (nb == 0)
		write(1, "0", 1);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
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
}
*/

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		(*f)(tab[i]);
		i++;
	}
}
/*
int	main(void)
{
	int tab[] = {1, 2, 3, 5, 4, 7, 6, 8, 9, 0};
	ft_foreach(tab, 10, &ft_putnbr);
}*/
